using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Project {
  public partial class MainPage : Form {

    public MainPage() {
      InitializeComponent();
    }

    private int UserID;
    bookSQL sql;
    private void MainPage_Load(object sender,EventArgs e) {

      sql = new bookSQL();

      using(LogInPage lPage = new LogInPage()) {
        if(lPage.ShowDialog() == DialogResult.OK) {
          UserID = LogInPage.ReturnValue1;
        } else {
          UserID = -1;
        }
      }

      if(UserID != -1) {
        LogIn.Visible = false;

        string query = "SELECT name FROM `user` WHERE (ID = " + UserID + ")";
        string UserName = sql.SelectStr(query);
        Hello.Text = "Hello " + UserName + " Welcome to ATHSHE";
      } else {
        LogIn.Visible = true;
      }
    }

    private void MyBooksButton_Click(object sender,EventArgs e) {
      if(UserID != -1) {
        MyBooks mBooks = new MyBooks(UserID);
        mBooks.MdiParent = this;
        mBooks.Show();
      } else {
        NotLogIn notL = new NotLogIn();
        notL.MdiParent = this;
        notL.Show();
      }
    }

    private void FollowingButton_Click(object sender,EventArgs e) {
      if(UserID != -1) {
        Following fol = new Following(UserID);
        fol.MdiParent = this;
        fol.Show();
      } else {
        NotLogIn notL = new NotLogIn();
        notL.MdiParent = this;
        notL.Show();
      }
    }

    private void MyProfileButton_Click(object sender,EventArgs e) {
      if(UserID != -1) {
        MyProfile mProfile = new MyProfile(UserID);
        mProfile.MdiParent = this;
        mProfile.Show();
      } else {
        NotLogIn notL = new NotLogIn();
        notL.MdiParent = this;
        notL.Show();
      }
    }

    private void Books_Click(object sender,EventArgs e) {
      if(UserID != -1) {
        Books book = new Books(UserID);
        book.MdiParent = this;
        book.Show();
      } else {
        NotLogIn notL = new NotLogIn();
        notL.MdiParent = this;
        notL.Show();
      }
    }

    private void LogIn_Click(object sender,EventArgs e) {
      sql = new bookSQL();

      using(LogInPage lPage = new LogInPage()) {
        if(lPage.ShowDialog() == DialogResult.OK) {
          UserID = LogInPage.ReturnValue1;
        }
      }

      if(UserID != -1) {
        LogIn.Visible = false;

        string query = "SELECT name FROM `user` WHERE (ID = " + UserID + ")";
        string UserName = sql.SelectStr(query);
        Hello.Text = "Hello " + UserName + " Welcome to ATHSHE";
      } else {
        LogIn.Visible = true;
      }
    }
  }
}
