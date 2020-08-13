#ifndef MAP_HPP
#define MAP_HPP

#include <iostream>
#include <vector>
#include <random>

namespace cs540{
    #define MAX_LEVEL 40

    template <typename Key_T, typename Value_T>
    class Map{
        private:
            typedef std::pair<const Key_T, Value_T> mapVal;

            class SkipList{
                public:
                    struct Node {
                        public:
                            std::vector<Node *> forward, backward;
                            bool dataVar;
                            Node(int levels, bool value = false):dataVar(value){
                                for (int i = 0; i <= levels; i++){
                                    forward.push_back(nullptr);
                                    backward.push_back(nullptr);
                                }
                            }
                            virtual ~Node() = default;
                            bool hasData(){
                                return dataVar;
                            }
                    };

                    struct DataNode : public Node{
                        DataNode(const mapVal d, int level) : Node(level), data(d){}
                        mapVal& getData(){
                            return data;
                        }

                        private:
                            mapVal data;
                    };

                    SkipList() : probability(0.5), maxLevel(MAX_LEVEL), currentLevel(0), 
                    lenght(0), head(new Node(maxLevel)), tail(new Node(maxLevel)){
                        for (int i = 0; i <= maxLevel; i++)
                        {
                            head->forward[i] = tail;
                            head->backward[i] = nullptr;

                            tail->backward[i] = head;
                            tail->forward[i] = nullptr;
                        }
                    }
                    ~SkipList(){
                        Node* p = head->forward[0];
                        Node* n = head;
                        while(p!=tail){
                            delete n;
                            n=p;
                            p=p->forward[0];
                        }
                        delete n;
                    }
                    size_t getSize(){
                        return lenght;
                    }
                    bool insert(mapVal val){
                        bool added = false;
                        int r = 0;
                        Key_T key = val.first;
                        Node* node = head;
                        std::vector<Node *> update = head->forward;
                        
                        for(int i = currentLevel; i >= 0; i--){
                            while(node->forward[i] != tail && node->forward[i] && static_cast<typename SkipList::DataNode *>
                                 (node->forward[i])->getData().first < key){
                                node = node->forward[i]; 
                            }
                            update[i] = node;
                        } 

                        node = node->forward[0];

                        if(node == nullptr || node == tail || !(static_cast<typename SkipList::DataNode *>
                          (node)->getData().first == key)){
                            
                            r = randLevel();
                            if(r>currentLevel){
                                for (int i=currentLevel;i<r;i++){
                                    update[i+1] = head;
                                }
                                currentLevel = r;
                            }
                            
                            DataNode* nodeData = new DataNode(val,r);

                            for(int i=0; i <= r; i++){
                                if (update[i] == head)
                                {
                                    nodeData->forward[i] = head->forward[i];
                                    nodeData->backward[i] = head;
                                    head->forward[i]->backward[i] = nodeData;
                                    head->forward[i] = nodeData;
                                }
                                else if (update[i] == tail)
                                {
                                    nodeData->forward[i] = tail;
                                    nodeData->backward[i] = tail->backward[i];
                                    tail->backward[i]->forward[i] = nodeData;
                                    tail->backward[i] = nodeData;
                                }
                                else
                                {
                                    nodeData->forward[i] = update[i] -> forward[i];
                                    nodeData->backward[i] = update[i];
                                    update[i]->forward[i] ->backward[i] = nodeData;
                                    update[i]->forward[i] = nodeData;
                                }
                                
                            }
                            added = true;
                            lenght++;
                        }
                        return added;
                    }
                    Node* find(const Key_T key){
                        if(lenght>0){
                            Node* node = head;
                            for(int i = currentLevel; i >= 0; i--){
                                while(node->forward[i] != tail && static_cast<typename SkipList::DataNode *>
                                     (node->forward[i])->getData().first < key){
                                    node = node->forward[i]; 
                                }
                            } 
                            node = node->forward[0];
                            if(node == nullptr || node == head || node == tail || !(static_cast<typename SkipList::DataNode *>
                              (node)->getData().first == key)){
                                return nullptr;
                            }
                            else{
                                return node;
                            }
                        }
                        return nullptr;
                    }
                    bool del (const Key_T key){
                        bool deleted = false;
                        if(lenght>0){
                            Node* node = head;
                            std::vector<Node *> update = head->forward;
                            for(int i = currentLevel; i >= 0; i--){
                                while(node->forward[i] != tail && static_cast<typename SkipList::DataNode *>
                                     (node->forward[i])->getData().first < key){
                                    node = node->forward[i]; 
                                }
                                update[i] = node;
                            } 
                            node = node->forward[0];
                            if( node != tail && static_cast<typename SkipList::DataNode *>
                              (node)->getData().first == key){
                                for (int i=0;i<currentLevel+1;i++){
                                    if(update[i]->forward[i] == node){
                                        update[i]->forward[i] = node->forward[i];
                                        node->forward[i]->backward[i] = update[i];
                                    }
                                    else{
                                        break;
                                    }
                                }
                                delete node;
                                lenght--;

                                while(currentLevel > 0 && head->forward[currentLevel] == tail){
                                    currentLevel--;
                                }
                                deleted = true;
                            }
                        }
                        return deleted;
                    }
                    int randLevel(){
                        float r = (float)(rand()%MAX_LEVEL)/maxLevel;
                        int lvl = 0; 
                        while(r < probability && lvl < maxLevel) 
                        { 
                            lvl++; 
                            r = (float)(rand()%MAX_LEVEL)/maxLevel;
                        } 
                        return lvl; 
                    }
                    
                    Node* getHead(){
                        return head;
                    }

                    Node* getTail(){
                        return tail;
                    }

                private:
                    const float probability;
                    int maxLevel, currentLevel, lenght;
                    Node *head, *tail;
            };

        public:
            class ConstIterator;
            class ReverseIterator;

            class Iterator
            {
                public:  
                
                    typename SkipList::Node *Ptr;   
                    //delete constructor               
                    Iterator() = delete;
                    Iterator(typename SkipList::Node *node) : Ptr(node){}
                    Iterator(const Iterator &iter) : Ptr(iter.Ptr){}
                    ~Iterator(){}
                    
                    Iterator& operator=(const Iterator &node){
                        Ptr = node.Ptr;
                        return *this;
                    }

                    Iterator &operator++(){
                        Ptr = Ptr->forward[0];
                        return *this;
                    }

                    Iterator operator++(int){
                        auto &i = *this;
                        Ptr = Ptr->forward[0];
                        return i;
                    }

                    Iterator &operator--(){
                        Ptr = Ptr->backward[0];
                        return *this;
                    }

                    Iterator operator--(int){
                        auto &i = *this;
                        Ptr = Ptr->backward[0];
                        return i;
                    }

                    mapVal& operator*() const{
                        return static_cast<typename SkipList::DataNode *>(Ptr)->getData();
                    }

                    mapVal* operator->() const{
                        return &(static_cast<typename SkipList::DataNode *>(Ptr)->getData());
                    }

                    //friend because can be used fr const and normal iterator
                    friend bool operator==(const Iterator &one, const Iterator &two){
                        if(one.Ptr != nullptr && two.Ptr != nullptr && one.Ptr->hasData() && two.Ptr->hasData()){
                            return (static_cast<typename SkipList::DataNode *>(one.Ptr)->getData()) == 
                            (static_cast<typename SkipList::DataNode *>(two.Ptr)->getData());
                        } 
                        return one.Ptr == two.Ptr;
                    }

                    friend bool operator==(const Iterator &one, const ConstIterator &two){
                        if(one.Ptr != nullptr && two.Ptr != nullptr && one.Ptr->hasData() && two.Ptr->hasData()){
                            return (static_cast<typename SkipList::DataNode *>(one.Ptr)->getData()) == 
                            (static_cast<typename SkipList::DataNode *>(two.Ptr)->getData());
                        } 
                        return one.Ptr == two.Ptr;
                    }

                    friend bool operator!=(const Iterator &one, const Iterator &two){
                        if(one.Ptr != nullptr && two.Ptr != nullptr && one.Ptr->hasData() && two.Ptr->hasData()){
                            return !((static_cast<typename SkipList::DataNode *>(one.Ptr)->getData()) == 
                            (static_cast<typename SkipList::DataNode *>(two.Ptr)->getData()));
                        } 
                        return !(one.Ptr == two.Ptr);
                    }

                    friend bool operator!=(const Iterator &one, const ConstIterator &two){
                        if(one.Ptr != nullptr && two.Ptr != nullptr && one.Ptr->hasData() && two.Ptr->hasData()){
                            return !((static_cast<typename SkipList::DataNode *>(one.Ptr)->getData()) == 
                            (static_cast<typename SkipList::DataNode *>(two.Ptr)->getData()));
                        } 
                        return !(one.Ptr == two.Ptr);
                    }
            };

            class ConstIterator
            {
                public: 
                    typename SkipList::Node *Ptr;

                    //delete constructor 
                    ConstIterator() = delete;
                    ConstIterator(typename SkipList::Node *node) : Ptr(node){}
                    ConstIterator(const ConstIterator &iter) : Ptr(iter.Ptr){}
                    ConstIterator(const Iterator &iter) : Ptr(iter.Ptr){}
                    ~ConstIterator(){}

                    ConstIterator& operator=(const ConstIterator &node){
                        Ptr = node.Ptr;
                        return *this;
                    }

                    ConstIterator &operator++(){
                        Ptr = Ptr->forward[0];
                        return *this;
                    }

                    ConstIterator operator++(int){
                        auto &i = *this;
                        Ptr = Ptr->forward[0];
                        return i;
                    }

                    ConstIterator &operator--(){
                        Ptr = Ptr->backward[0];
                        return *this;
                    }

                    ConstIterator operator--(int){
                        auto &i = *this;
                        Ptr = Ptr->backward[0];
                        return i;
                    }

                    const mapVal& operator*() const{
                        return static_cast<typename SkipList::DataNode *>(Ptr)->getData();
                    }

                    const mapVal* operator->() const{
                        return &(static_cast<typename SkipList::DataNode *>(Ptr)->getData());
                    }
                    
                    friend bool operator==(const ConstIterator &one, const ConstIterator &two){
                        if(one.Ptr != nullptr && two.Ptr != nullptr && one.Ptr->hasData() && two.Ptr->hasData()){
                            return (static_cast<typename SkipList::DataNode *>(one.Ptr)->getData()) == 
                            (static_cast<typename SkipList::DataNode *>(two.Ptr)->getData());
                        } 
                        return one.Ptr == two.Ptr;
                    }

                    friend bool operator==(const ConstIterator &one, const Iterator &two){
                        if(one.Ptr != nullptr && two.Ptr != nullptr && one.Ptr->hasData() && two.Ptr->hasData()){
                            return (static_cast<typename SkipList::DataNode *>(one.Ptr)->getData()) == 
                            (static_cast<typename SkipList::DataNode *>(two.Ptr)->getData());
                        } 
                        return one.Ptr == two.Ptr;
                    }

                    friend bool operator !=(const ConstIterator &one, const ConstIterator &two){
                        if(one.Ptr != nullptr && two.Ptr != nullptr && one.Ptr->hasData() && two.Ptr->hasData()){
                            return (static_cast<typename SkipList::DataNode *>(one.Ptr)->getData()) != 
                            (static_cast<typename SkipList::DataNode *>(two.Ptr)->getData());
                        } 
                        return one.Ptr == two.Ptr;
                    }

                    friend bool operator !=(const ConstIterator &one, const Iterator &two){
                        if(one.Ptr != nullptr && two.Ptr != nullptr && one.Ptr->hasData() && two.Ptr->hasData()){
                            return (static_cast<typename SkipList::DataNode *>(one.Ptr)->getData()) != 
                            (static_cast<typename SkipList::DataNode *>(two.Ptr)->getData());
                        } 
                        return one.Ptr == two.Ptr;
                    }
            };

            class ReverseIterator
            {
                public:
                    typename SkipList::Node *Ptr;
    
                    //delete constructor 
                    ReverseIterator() = delete;
                    ReverseIterator(typename SkipList::Node *n) : Ptr(n){}
                    ReverseIterator(const ReverseIterator &revit):Ptr(revit.Ptr){}
                    ~ReverseIterator(){}

                    ReverseIterator& operator=(const ReverseIterator &node){
                        Ptr = node.Ptr;
                        return *this;
                    }

                    ReverseIterator &operator++(){
                        Ptr = Ptr->backward[0];
                        return *this;
                    }

                    ReverseIterator operator++(int){
                        auto &i = *this;
                        Ptr = Ptr->backward[0];
                        return i;
                    }

                    ReverseIterator &operator--(){
                        Ptr = Ptr->forward[0];
                        return *this;
                    }

                    ReverseIterator operator--(int){
                        auto &i = *this;
                        Ptr = Ptr->forward[0];
                        return i;
                    }

                    mapVal& operator*() const{
                        return static_cast<typename SkipList::DataNode *>(Ptr)->getData();
                    }

                    mapVal* operator->() const{
                        return &(static_cast<typename SkipList::DataNode *>(Ptr)->getData());
                    }
                    
                    friend bool operator==(const ReverseIterator &one, const ReverseIterator &two){
                        if(one.Ptr != nullptr && two.Ptr != nullptr && one.Ptr->hasData() && two.Ptr->hasData()){
                            return (static_cast<typename SkipList::DataNode *>(one.Ptr)->getData()) == 
                            (static_cast<typename SkipList::DataNode *>(two.Ptr)->getData());
                        } 
                        return one.Ptr == two.Ptr;
                    }

                    friend bool operator !=(const ReverseIterator &one, const ReverseIterator &two){
                        if(one.Ptr != nullptr && two.Ptr != nullptr && one.Ptr->hasData() && two.Ptr->hasData()){
                                return (static_cast<typename SkipList::DataNode *>(one.Ptr)->getData()) != 
                            (static_cast<typename SkipList::DataNode *>(two.Ptr)->getData());
                            return false;
                        } 
                        return one.Ptr == two.Ptr;
                    }
            };

            Map() : sList(new SkipList()){}

            Map(const Map &o) : sList(new SkipList()){
                for (auto it = o.begin();it!=o.end(); it++){
                    sList->insert(*it);
                }
            }

            Map &operator=(const Map &o){
                for (auto it = o.begin();it!=o.end(); it++){
                    sList->insert(*it);
                }
                return *this;
            }

            Map(std::initializer_list<std::pair<const Key_T, Value_T> > initList) : sList(new SkipList()){
                for (auto i : initList)
                {
                    insert(i);
                }
            }

            ~Map(){
                delete sList;
            }
            
            size_t size() const{
                return sList->getSize();
            }

            bool empty() const{
                return sList->getSize()==0;
            }

            Iterator begin(){
                return Iterator(sList->getHead()->forward[0]);
            }

            Iterator end(){
                return Iterator(sList->getTail());
            }
            
            ConstIterator begin() const{
                return ConstIterator(sList->getHead()->forward[0]);
            }

            ConstIterator end() const{
                return ConstIterator(sList->getTail());
            }

            ReverseIterator rbegin(){
                return ReverseIterator(sList->getTail()->backward[0]);
            }

            ReverseIterator rend(){
                return ReverseIterator(sList->getHead());
            }

            Iterator find(const Key_T &key){
                auto node = sList->find(key);
                if (node == nullptr)
                {
                    return end();
                }
                else{
                    return Iterator(node);
                }
            }

            ConstIterator find(const Key_T &key) const{
                auto node = sList->find(key);
                if (node == nullptr)
                {
                    return end();
                }
                else{
                    return Iterator(node);
                }
            }

            Value_T &at(const Key_T &key){
                auto node = sList->find(key);
                if (node == nullptr)
                {
                    throw std::out_of_range("Key not in range");
                }
                else{
                    return (static_cast<typename SkipList::DataNode *>(node)->getData().second);
                }
            }

            const Value_T &at(const Key_T &key) const{
                auto node = sList->find(key);
                if (node == nullptr)
                {
                    throw std::out_of_range("Key not in range");
                }
                else{
                    return (static_cast<typename SkipList::DataNode *>(node)->getData().second);
                }
            }

            Value_T &operator[](const Key_T &key){
                auto node = sList->find(key);
                if (node == nullptr)
                {
                    sList->insert(std::make_pair(key, Value_T()));
                    node = sList->find(key);
                }
                return (static_cast<typename SkipList::DataNode *>(node)->getData().second);
            }

            std::pair<Iterator, bool> insert(const mapVal &value){
                bool inst = sList->insert(value);
                Iterator iter = find(value.first);

                return std::make_pair(iter, inst);
            }
            
            template <typename IT_T>
            void insert(IT_T ranBegin, IT_T ranEnd){
                for (auto i = ranBegin; i != ranEnd; i++)
                {
                    insert(i);
                }
            }

            void erase(Iterator it){
                bool d = sList->del(static_cast<typename SkipList::DataNode *>(it.Ptr)->getData().first);
                if(!d){
                    throw std::out_of_range("Key not in range");
                }
            }

            void erase(const Key_T &key){
                bool d = sList->del(key);
                if(!d){
                    throw std::out_of_range("Key not in range");
                }
            }

            void clear(){
                delete sList;
                sList = new SkipList();
            }

            friend bool operator==(const Map<Key_T, Value_T> &one, const Map<Key_T, Value_T> two){
                auto twoIter = two.begin();
                if(one.size() == two.size()){
                    for(auto oneIter = one.begin(); oneIter!= two.end();oneIter++){
                        if(oneIter != twoIter){
                            return false;
                        }
                    }
                    return true;
                }
                return false;
            }

            friend bool operator !=(const Map<Key_T, Value_T> &one, const Map<Key_T, Value_T> &two){
                return one!=two;
            }
            friend bool operator<(const Map<Key_T, Value_T> &one, const Map<Key_T, Value_T> &two){
                if(one.size()>two.size()){
                    auto oneIter = one.begin();
                    for(auto twoIter = two.begin(); twoIter!=two.end();twoIter++){
                        if(twoIter > oneIter){
                            return true;
                        }
                    }
                }
                else{
                    return true;
                }
                return false;

            }
        private:
            Map<Key_T, Value_T>::SkipList *sList;
    };
}

#endif

