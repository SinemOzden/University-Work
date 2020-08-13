#ifndef SHAREDPTR_HPP
#define SHAREDPTR_HPP

#include <cstddef>
#include <iostream>
#include <atomic>

namespace cs540
{
    static pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
    template <typename T> class SharedPtr;

    template<class T> void castDeleter(const void *p){
        delete static_cast<const T*>(p);
    }

    struct refCount{
    public:
        std::atomic_int counter;
        const void *pointer;
        void (*castDel)(const void *);

        refCount():counter(0){}
        refCount(const void *ptr) : counter(0), pointer(ptr) {}
        refCount(const refCount &old) = default;
        ~refCount() {
            if (pointer && castDel){
                (*castDel)(pointer);
            }
            pointer = nullptr;
        }
        int count() const{
            return counter;
        }
        void AddRef(){
            counter++;
        }
        void DelRef(){
            counter--;
        }
    };

    template <typename T1, typename T2> bool operator==(const SharedPtr<T1> &p1, const SharedPtr<T2> &p2){
        return p1.get() == p2.get();
    }

    template <typename T> bool operator==(const SharedPtr<T> &p, std::nullptr_t nullp){
        return (p.get() == nullp);
    }

    template <typename T> bool operator==(std::nullptr_t nullp, const SharedPtr<T> &p){
        return (p.get() == nullp);
    }

    template <typename T1, typename T2> bool operator!=(const SharedPtr<T1>&p1, const SharedPtr<T2> &p2){
        return !(p1==p2);
    }

    template <typename T> bool operator!=(const SharedPtr<T> &p, std::nullptr_t nullp){
        return !(p == nullp);
    }

    template <typename T> bool operator!=(std::nullptr_t nullp, const SharedPtr<T> &p){
        return !(p == nullp);
    }

    template <typename T, typename U> SharedPtr<T> static_pointer_cast(const SharedPtr<U> &sp){
        auto p = static_cast<T*>(sp.get());
        SharedPtr<T> sptr = SharedPtr<T>();

        sptr.setPtr(p);
        sptr.setRCount(sp.getRCount());

        pthread_mutex_lock(&mutex);
        sptr.rCount->AddRef();
        pthread_mutex_unlock(&mutex);

        return sptr;
    }

    template <typename T, typename U> SharedPtr<T> dynamic_pointer_cast(const SharedPtr<U> &sp){
        auto p = dynamic_cast<T*>(sp.get());
        SharedPtr<T> sptr = SharedPtr<T>();

        sptr.setPtr(p);
        sptr.setRCount(sp.getRCount());

        pthread_mutex_lock(&mutex);
        sptr.rCount->AddRef();
        pthread_mutex_unlock(&mutex);

        return sptr;
    }

    template <typename T> class SharedPtr{
    public:
        T *val;
        refCount *rCount;

        SharedPtr():val(nullptr), rCount(nullptr) {}

        template <typename U> explicit SharedPtr(U *p): val(p), rCount(new refCount(val)){
            pthread_mutex_lock(&mutex);
            if (rCount){
                rCount->castDel = &castDeleter<U>;
                rCount->AddRef();
            }
            pthread_mutex_unlock(&mutex);
        }

        SharedPtr(const SharedPtr &p): val(p.val), rCount(p.rCount){
            pthread_mutex_lock(&mutex);
            if (rCount){
                rCount->AddRef();
            }
            pthread_mutex_unlock(&mutex);
        }

        template <typename U> SharedPtr(const SharedPtr<U> &p): val(p.val), rCount(p.rCount){
            pthread_mutex_lock(&mutex);
            if (rCount){
                rCount->castDel = &castDeleter<U>;
                rCount->AddRef();
            }
            pthread_mutex_unlock(&mutex);
        }

        SharedPtr(SharedPtr &&p): val(std::move(p.val)), rCount(p.rCount){
            p.val = nullptr;
            p.rCount = nullptr;
        }

        template <typename U> SharedPtr(SharedPtr<U> &&p): val(std::move(p.val)), rCount(p.rCount){
            pthread_mutex_lock(&mutex);
            if (rCount){
                rCount->castDel = &castDeleter<U>;
            }
            pthread_mutex_unlock(&mutex);
            p.val = nullptr;
            p.rCount = nullptr;
        }

        SharedPtr &operator=(const SharedPtr &p){
            if (this != &p){
                pthread_mutex_lock(&mutex);
                if (rCount){
                    if(rCount->count() > 0){
                        rCount->DelRef();
                    }
                    if (rCount->count() == 0){
                        delete rCount;
                        rCount = nullptr;
                    }
                }

                val = p.val;
                rCount = p.rCount;
                if (rCount){
                    rCount->AddRef();
                }
                pthread_mutex_unlock(&mutex);
            }
            
            return *this;
        }

        template <typename U> SharedPtr<T> &operator=(const SharedPtr<U> &p){
            pthread_mutex_lock(&mutex);
            if (rCount){
                if(rCount->count() > 0){
                    rCount->DelRef();
                }
                if (rCount->count() == 0){
                    delete rCount;
                    rCount = nullptr;
                }
            }

            val = p.val;
            rCount = p.rCount;
            if (rCount){
                rCount->castDel = &castDeleter<U>;
                rCount->AddRef();
            }
            pthread_mutex_unlock(&mutex);

            return *this;
        }

        SharedPtr &operator=(SharedPtr &&p){
            pthread_mutex_lock(&mutex);
            if (rCount){
                if(rCount->count() > 0){
                    rCount->DelRef();
                }
                if (rCount->count() == 0){
                    delete rCount;
                    rCount = nullptr;
                }
            }
            val = std::move(p.val);
            rCount = p.rCount;
            pthread_mutex_unlock(&mutex);

            p.val = nullptr;
            p.rCount = nullptr;

            return *this;
        }

        template <typename U> SharedPtr &operator=(SharedPtr<U> &&p){
            if (this->val != p.val)
            {
                pthread_mutex_lock(&mutex);
                if (rCount){
                    if(rCount->count() > 0){
                        rCount->DelRef();
                    }
                    if (rCount->count() == 0){
                        delete rCount;
                        rCount = nullptr;
                    }
                }
                val = std::move(p.val);
                rCount = p.rCount;
                if (rCount){
                    rCount->castDel = &castDeleter<U>;
                }
                pthread_mutex_unlock(&mutex);
            }

            p.val = nullptr;
            p.rCount = nullptr;

            return *this;
        }

        ~SharedPtr(){
            pthread_mutex_lock(&mutex);
            if (rCount != nullptr){
                if(rCount->count() > 0){
                    rCount->DelRef();
                }
                if (rCount->count() == 0){
                    delete rCount;
                    rCount = nullptr;
                }
            }
            pthread_mutex_unlock(&mutex);
        }

        void reset(){
            pthread_mutex_lock(&mutex);
            if (rCount){
                if(rCount->count() > 0){
                    rCount->DelRef();
                }
                if (rCount->count() == 0){
                    delete rCount;
                    rCount = nullptr;
                }
            }
            rCount = nullptr;
            pthread_mutex_unlock(&mutex);
            val = nullptr;
        }

        template <typename U> void reset(U *p){
            pthread_mutex_lock(&mutex);
            if (rCount){
                if(rCount->count() > 0){
                    rCount->DelRef();
                }
                if (rCount && rCount->count() == 0){
                    delete rCount;
                    rCount = nullptr;
                }
            }
            rCount = new refCount(p);
            if (rCount)
            {
                rCount->castDel = &castDeleter<U>;
                rCount->AddRef();
            }
            pthread_mutex_unlock(&mutex);

            val = p;
        }

        T *get() const{
            return val;
        }

        refCount* getRCount() const
        {
            return rCount;
        }

        void setPtr(T *ptr)
        {
            val = ptr;
        }

        void setRCount(refCount *rctmp)
        {
            rCount = rctmp;
        }

        T &operator*() const{
            return *val;
        }

        T *operator->() const{
            return val;
        }

        explicit operator bool() const{
            return (val != nullptr);
        }
    };
}

#endif