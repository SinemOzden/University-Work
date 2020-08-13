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
  public partial class LogInPage : Form {

    public static int ReturnValue1 { get; set; }
    private int ID;

    public LogInPage() {
      InitializeComponent();
    }

    private bookSQL sql;

    private void LogInPage_Load(object sender,EventArgs e) {
      sql = new bookSQL();
      ID = -1;
      ReturnValue1 = ID;
    }

    private void SignUpButton_Click(object sender,EventArgs e) {
      SignUp sUp = new SignUp();
      sUp.ShowDialog();
    }

    private void OkButton_Click(object sender,EventArgs e) {
      //check if password and username match
      string uName = UserNameTBox.Text;
      string pWord = PasswordTBox.Text;
      ID = -1;

      if(CheckValid(uName,pWord)) {
        //get id
        string query = "SELECT ID FROM `user` WHERE (name = '" + uName.ToString() + "')";
        ID = sql.SelectInt(query);

        this.DialogResult = DialogResult.OK;
        ReturnValue1 = ID;

      } else {
        PWordNotMatch not = new PWordNotMatch();
        not.ShowDialog();
      }
    }
    private void PasswordTBox_KeyDown(object sender,KeyEventArgs e) {
      string uName = "", pWord = "";
      ID = -1;

      if(e.KeyCode == Keys.Enter)//enter giriline kadar bekle
      {
        uName = UserNameTBox.Text;
        pWord = PasswordTBox.Text;
        if(CheckValid(uName,pWord)) {
          //get id
          string query = "SELECT ID FROM `user` WHERE (name = '" + uName.ToString() + "')";
          ID = sql.SelectInt(query);

          this.DialogResult = DialogResult.OK;
          ReturnValue1 = ID;
        } else {
          PWordNotMatch not = new PWordNotMatch();
          not.ShowDialog();
        }
      }
      //check if password and username match
    }

    private bool CheckValid(string uName,string pWord) {
      string query = "SELECT password FROM `user` WHERE (name = '" + uName + "')";
      string SQL_p = sql.SelectStr(query);
      if(SQL_p == pWord) {
        return true;
      } else {
        return false;
      }
      //check if name and e mail unique
    }

  }
}
