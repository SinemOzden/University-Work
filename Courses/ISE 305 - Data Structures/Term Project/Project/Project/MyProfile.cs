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
  public partial class MyProfile : Form {
    private int UserID;
    private bookSQL sql;

    public MyProfile(int ID) {
      InitializeComponent();
      UserID = ID;
    }

    private void MyProfile_Load(object sender,EventArgs e) {
      //get USer Name- email

      sql = new bookSQL();
      string query = "SELECT name FROM `user` WHERE (ID = '" + UserID + "')";
      string uName = sql.SelectStr(query);

      query = "SELECT email FROM `user` WHERE (ID = '" + UserID + "')";
      string email = sql.SelectStr(query);
      
      UserName.Text = uName;
      eMail.Text = email;
    }

    private void ChangePassword_Click(object sender,EventArgs e) {
      ChangePassword fol = new ChangePassword(UserID);
      fol.MdiParent = ParentForm;
      fol.Show();
    }
  }
}
