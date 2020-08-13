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
  public partial class EditBook : Form {

    private string[] stringRowInfo = new string[5];
    private bookSQL sql;
    private int bookID;
    private int UserID;
    private bool inList;

    public EditBook(List<string> stringRowI, int ID) {
      InitializeComponent();

      stringRowI.CopyTo(stringRowInfo);

      UserID = ID;
    }

    private void EditBook_Load(object sender,EventArgs e) {

      sql = new bookSQL();

      BookName.Text = stringRowInfo[0];
      WriterName.Text = stringRowInfo[1];
      PublisherName.Text = stringRowInfo[2];
      TranslatorName.Text = stringRowInfo[3];
      string type = stringRowInfo[4];

      if(type == "null") {
        inList = false;
        Delete.Visible = false;
      } else {
        inList = true;
        Delete.Visible = true;
      }

      string query = "SELECT ID FROM `book` WHERE (name = '" + stringRowInfo[0] + "')";
      bookID = sql.SelectInt(query);

      query = "SELECT comment FROM `userBook` WHERE (bookID = '" + bookID + "') AND (UserID = " + UserID + ")";
      string com = sql.SelectStr(query);
      comment.Text = com;

      query = "SELECT rate FROM `userBook` WHERE (bookID = '" + bookID + "') AND (UserID = " + UserID + ")";
      int rate = sql.SelectInt(query);
      if(rate != -1) {
        comboBox1.SelectedIndex = rate;
      }
      

      if(type == "Already Read") {
        AlreadyRead.Checked = true;
        NowReading.Checked = false;
        WantToRead.Checked = false;
      } else if(type == "Now Reading") {
        AlreadyRead.Checked = false;
        NowReading.Checked = true;
        WantToRead.Checked = false;
      } else if(type == "Want to Read"){
        AlreadyRead.Checked = false;
        NowReading.Checked = false;
        WantToRead.Checked = true;
      } else {
        AlreadyRead.Checked = false;
        NowReading.Checked = false;
        WantToRead.Checked = false;
      }
      
    }

    private void Save_Click(object sender,EventArgs e) {
      string type;

      if(AlreadyRead.Checked == true) {
        type = "Already Read";
      }
      else if(NowReading.Checked == true) {
        type = "Now Reading";
      } else {
        type = "Want to Read";
      }

      string query;
      if(inList) {
        query = "UPDATE `userBook` SET `type`= '" + type + "', `rate` = "
        + comboBox1.SelectedIndex.ToString() + ", `comment` = '" + comment.Text
        + "' WHERE (UserID = " + UserID + ") AND (bookID = " + bookID + ")";
        sql.Update(query);
      } else {
        query = "INSERT INTO `userbook`(`bookID`, `userID`, `type`, `rate`, `comment`) "+
          "VALUES(" + bookID + "," + UserID + ",'" + type + "', '" + comboBox1.SelectedIndex.ToString() +
          "', '" + comment.Text + "')";
        sql.Insert(query);
      }

      query = "UPDATE `book` SET `rate`= (`rate` * `vote` + " + comboBox1.SelectedIndex.ToString() +
        ") / (`vote`+1), `vote`= `vote` +1 WHERE id = " + bookID;
      sql.Update(query);
      this.Close();

    }

    private void Delete_Click(object sender,EventArgs e) {
      string query = "SELECT ID FROM `book` WHERE (name = '" + stringRowInfo[0] + "')";
      int ID = sql.SelectInt(query);
      bool ok = false;

      using(AreYouSure sure = new AreYouSure(stringRowInfo[0])) {
        if(sure.ShowDialog() == DialogResult.OK) {
          ok = AreYouSure.ReturnValue1;
        }
      }

      if(ok) {
        query = "DELETE FROM `userBook` WHERE (UserID = " + UserID + ") AND (bookID = " + ID + ")";
        sql.Delete(query);
        this.Close();
      } else {
        MessageBox.Show("Book not Deleted");
      }
    }
  }
}
