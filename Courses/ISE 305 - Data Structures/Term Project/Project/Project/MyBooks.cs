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
  public partial class MyBooks : Form {
    private int UserID;

    public MyBooks(int ID) {
      InitializeComponent();
      UserID = ID;
    }
    private bookSQL sql;
    private DataTable table;

    private void MyBooks_Load(object sender,EventArgs e) {
      toolStripLabel.Text = "All";
      sql = new bookSQL();

      string query = "SELECT book.Name AS 'Book Name', writer.name AS 'Writer Name', publisher.name AS 'Publisher Name', " +
        "translator.Name AS 'Translator Name', type AS 'Type' FROM `user`, `userbook`, `book`, " + 
        "`fullbook`, `publisher`, `person` AS writer, `person` AS translator " + 
        "WHERE ((book.ID = userbook.bookID) AND (writer.ID = writerID) AND " + 
        "(publisher.ID = publisherID) AND (translator.ID = translatorID) AND " +
        "(book.ID = fullbook.bookID) AND (user.ID = userbook.userID) AND  (user.ID = " + UserID + "))";
      table = sql.SelectTable(query);
      dataGridView1.ReadOnly = true;
      dataGridView1.DataSource = table;
    }

    private void WantToRead_Click(object sender,EventArgs e) {
      toolStripLabel.Text = "Want To Read";

      string query = "SELECT book.Name AS 'Book Name', writer.name AS 'Writer Name', publisher.name AS 'Publisher Name', " +
        "translator.Name AS 'Translator Name', type AS 'Type' FROM `user`, `userbook`, `book`, " +
        "`fullbook`, `publisher`, `person` AS writer, `person` AS translator " +
        "WHERE ((book.ID = userbook.bookID) AND (writer.ID = writerID) AND " +
        "(publisher.ID = publisherID) AND (translator.ID = translatorID) AND " +
        "(book.ID = fullbook.bookID) AND (user.ID = userbook.userID) AND (user.ID = " + UserID + ") AND (type = 'Want to Read'))";
      table = sql.SelectTable(query);
      dataGridView1.ReadOnly = true;
      dataGridView1.DataSource = table;
    }

    private void NowReading_Click(object sender,EventArgs e) {
      toolStripLabel.Text = "Now Reading";

      string query = "SELECT book.Name AS 'Book Name', writer.name AS 'Writer Name', publisher.name AS 'Publisher Name', " +
        "translator.Name AS 'Translator Name', type AS 'Type' FROM `user`, `userbook`, `book`, " +
        "`fullbook`, `publisher`, `person` AS writer, `person` AS translator " +
        "WHERE ((book.ID = userbook.bookID) AND (writer.ID = writerID) AND " +
        "(publisher.ID = publisherID) AND (translator.ID = translatorID) AND " +
        "(book.ID = fullbook.bookID) AND (user.ID = userbook.userID) AND (user.ID =  " + UserID + ") AND (type = 'Now Reading'))";
      table = sql.SelectTable(query);
      dataGridView1.ReadOnly = true;
      dataGridView1.DataSource = table;
    }

    private void AlreadyRead_Click(object sender,EventArgs e) {
      toolStripLabel.Text = "Already Read";

      string query = "SELECT book.Name AS 'Book Name', writer.name AS 'Writer Name', publisher.name AS 'Publisher Name', " +
        "translator.Name AS 'Translator Name', type AS 'Type' FROM `user`, `userbook`, `book`, " +
        "`fullbook`, `publisher`, `person` AS writer, `person` AS translator " +
        "WHERE ((book.ID = userbook.bookID) AND (writer.ID = writerID) AND " +
        "(publisher.ID = publisherID) AND (translator.ID = translatorID) AND " +
        "(book.ID = fullbook.bookID) AND (user.ID = userbook.userID) AND (user.ID =  " + UserID + ") AND (type = 'Already Read'))";
      table = sql.SelectTable(query);
      dataGridView1.ReadOnly = true;
      dataGridView1.DataSource = table;
    }

    private void dataGridView1_CellDoubleClick(object sender,DataGridViewCellEventArgs e) {
      List<string> stringRowInfo = new List<string>();
      int index = e.RowIndex;

      DataGridViewRow selectedRow = dataGridView1.Rows[index];
      stringRowInfo.Add(selectedRow.Cells[0].Value.ToString());//Book Name
      stringRowInfo.Add(selectedRow.Cells[1].Value.ToString());//Writer Name
      stringRowInfo.Add(selectedRow.Cells[2].Value.ToString());//Publisher Name
      stringRowInfo.Add(selectedRow.Cells[3].Value.ToString());//Translator Name
      stringRowInfo.Add(selectedRow.Cells[4].Value.ToString());//Type

      EditBook eBooks = new EditBook(stringRowInfo,UserID);
      eBooks.MdiParent = ParentForm;
      eBooks.Show();

    }

    private void refresh_Click(object sender,EventArgs e) {
      if(toolStripLabel.Text == "All") {

        string query = "SELECT book.Name AS 'Book Name', writer.name AS 'Writer Name', publisher.name AS 'Publisher Name', " +
          "translator.Name AS 'Translator Name', type AS 'Type' FROM `user`, `userbook`, `book`, " +
          "`fullbook`, `publisher`, `person` AS writer, `person` AS translator " +
          "WHERE ((book.ID = userbook.bookID) AND (writer.ID = writerID) AND " +
          "(publisher.ID = publisherID) AND (translator.ID = translatorID) AND " +
          "(book.ID = fullbook.bookID) AND (user.ID = userbook.userID) AND  (user.ID = " + UserID + "))";
        table = sql.SelectTable(query);
        dataGridView1.ReadOnly = true;
        dataGridView1.DataSource = table;
      }else if(toolStripLabel.Text == "Already Read") {

        string query = "SELECT book.Name AS 'Book Name', writer.name AS 'Writer Name', publisher.name AS 'Publisher Name', " +
          "translator.Name AS 'Translator Name', type AS 'Type' FROM `user`, `userbook`, `book`, " +
          "`fullbook`, `publisher`, `person` AS writer, `person` AS translator " +
          "WHERE ((book.ID = userbook.bookID) AND (writer.ID = writerID) AND " +
          "(publisher.ID = publisherID) AND (translator.ID = translatorID) AND " +
          "(book.ID = fullbook.bookID) AND (user.ID = userbook.userID) AND (user.ID =  " + UserID + ") AND (type = 'Already Read'))";
        table = sql.SelectTable(query);
        dataGridView1.ReadOnly = true;
        dataGridView1.DataSource = table;
      }else if(toolStripLabel.Text == "Now Reading") {

        string query = "SELECT book.Name AS 'Book Name', writer.name AS 'Writer Name', publisher.name AS 'Publisher Name', " +
          "translator.Name AS 'Translator Name', type AS 'Type' FROM `user`, `userbook`, `book`, " +
          "`fullbook`, `publisher`, `person` AS writer, `person` AS translator " +
          "WHERE ((book.ID = userbook.bookID) AND (writer.ID = writerID) AND " +
          "(publisher.ID = publisherID) AND (translator.ID = translatorID) AND " +
          "(book.ID = fullbook.bookID) AND (user.ID = userbook.userID) AND (user.ID =  " + UserID + ") AND (type = 'Now Reading'))";
        table = sql.SelectTable(query);
        dataGridView1.ReadOnly = true;
        dataGridView1.DataSource = table;
      } else if(toolStripLabel.Text == "Want To Read") {

        string query = "SELECT book.Name AS 'Book Name', writer.name AS 'Writer Name', publisher.name AS 'Publisher Name', " +
          "translator.Name AS 'Translator Name', type AS 'Type' FROM `user`, `userbook`, `book`, " +
          "`fullbook`, `publisher`, `person` AS writer, `person` AS translator " +
          "WHERE ((book.ID = userbook.bookID) AND (writer.ID = writerID) AND " +
          "(publisher.ID = publisherID) AND (translator.ID = translatorID) AND " +
          "(book.ID = fullbook.bookID) AND (user.ID = userbook.userID) AND (user.ID = " + UserID + ") AND (type = 'Want to Read'))";
        table = sql.SelectTable(query);
        dataGridView1.ReadOnly = true;
        dataGridView1.DataSource = table;
      }
    }

    private void All_Click(object sender,EventArgs e) {
      toolStripLabel.Text = "All";

      string query = "SELECT book.Name AS 'Book Name', writer.name AS 'Writer Name', publisher.name AS 'Publisher Name', " +
        "translator.Name AS 'Translator Name', type AS 'Type' FROM `user`, `userbook`, `book`, " +
        "`fullbook`, `publisher`, `person` AS writer, `person` AS translator " +
        "WHERE ((book.ID = userbook.bookID) AND (writer.ID = writerID) AND " +
        "(publisher.ID = publisherID) AND (translator.ID = translatorID) AND " +
        "(book.ID = fullbook.bookID) AND (user.ID = userbook.userID) AND  (user.ID = " + UserID + "))";
      table = sql.SelectTable(query);
      dataGridView1.ReadOnly = true;
      dataGridView1.DataSource = table;
    }
  }
}
