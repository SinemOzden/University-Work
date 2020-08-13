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
  public partial class Books : Form {
    private int UserID;
    private string query;

    public Books(int uID) {
      InitializeComponent();
      UserID = uID;
    }
    private bookSQL sql;
    private void Books_Load(object sender,EventArgs e) {

      //admin id =0
      if(UserID == 0) {
        addBook.Visible = true;
        Refresh.Visible = true;
      } else {
        addBook.Visible = false;
        Refresh.Visible = false;
      }

      sql = new bookSQL();

      query = "SELECT book.Name AS 'Book Name', writer.name AS 'Writer Name', publisher.name AS " + 
        "'Publisher Name', translator.Name AS 'Translator Name', book.year AS 'Year', book.rate AS" +
        "'Rate' , book.vote AS 'Vote'" +
        "FROM `book`, `fullbook`, `publisher`, `person` AS writer, `person` AS translator " +
        "WHERE (writer.ID = writerID) AND " +
        "(publisher.ID = publisherID) AND (translator.ID = translatorID) AND " +
        "(book.ID = fullbook.bookID)";
      DataTable table = sql.SelectTable(query);
      dataGridView1.ReadOnly = true;
      dataGridView1.DataSource = table;
    }

    private void Search_Click(object sender,EventArgs e) {

      int bookID = -1;
      int writerID = -1;
      int publisherID = -1;
      query = "";

      using(Search search = new Search()) {
        if(search.ShowDialog(this) == DialogResult.OK) {
          bookID = search.ReturnValue1;
          writerID = search.ReturnValue2;
          publisherID = search.ReturnValue3;
        }
      }
      //once book ID al 
      //sonra 
      if(bookID != -1 & writerID != -1 & publisherID != -1) {

        query = "SELECT book.Name AS 'Book Name', writer.name AS 'Writer Name', publisher.name AS " +
        "'Publisher Name', translator.Name AS 'Translator Name', book.year AS 'Year', book.rate AS 'Rate', " +
        "book.vote AS 'Vote' FROM `book`, `fullbook`, `publisher`, `person` AS writer, `person` AS translator " +
        "WHERE (writer.ID = writerID) AND (publisher.ID = publisherID) AND (translator.ID = translatorID) " +
        "AND (book.ID = fullbook.bookID) AND (book.ID = " + bookID + ") AND (writerID = " + writerID + ") " +
        "AND (publisherID = " + publisherID + ")";

      } else if(bookID != -1 & writerID != -1 & publisherID == -1) {

        query = "SELECT book.Name AS 'Book Name', writer.name AS 'Writer Name', publisher.name AS " +
        "'Publisher Name', translator.Name AS 'Translator Name', book.year AS 'Year', book.rate AS 'Rate', " +
        "book.vote AS 'Vote' FROM `book`, `fullbook`, `publisher`, `person` AS writer, `person` AS translator " +
        "WHERE (writer.ID = writerID) AND (publisher.ID = publisherID) AND (translator.ID = translatorID) " +
        "AND (book.ID = fullbook.bookID) AND (book.ID = " + bookID + ") AND (writerID = " + writerID + ") ";

      }else if(bookID != -1 & writerID == -1 & publisherID == -1) {

        query = "SELECT book.Name AS 'Book Name', writer.name AS 'Writer Name', publisher.name AS " +
        "'Publisher Name', translator.Name AS 'Translator Name', book.year AS 'Year', book.rate AS 'Rate', " +
        "book.vote AS 'Vote' FROM `book`, `fullbook`, `publisher`, `person` AS writer, `person` AS translator " +
        "WHERE (writer.ID = writerID) AND (publisher.ID = publisherID) AND (translator.ID = translatorID) " +
        "AND (book.ID = fullbook.bookID) AND (book.ID = " + bookID + ")";      

      } else if(bookID == -1 & writerID != -1 & publisherID != -1) {

        query = "SELECT book.Name AS 'Book Name', writer.name AS 'Writer Name', publisher.name AS " +
        "'Publisher Name', translator.Name AS 'Translator Name', book.year AS 'Year', book.rate AS 'Rate', " +
        "book.vote AS 'Vote' FROM `book`, `fullbook`, `publisher`, `person` AS writer, `person` AS translator " +
        "WHERE (writer.ID = writerID) AND (publisher.ID = publisherID) AND (translator.ID = translatorID) " +
        "AND (book.ID = fullbook.bookID) AND (writerID = " + writerID + ") " +
        "AND (publisherID = " + publisherID + ")";

      } else if(bookID == -1 & writerID != -1 & publisherID == -1) {

        query = "SELECT book.Name AS 'Book Name', writer.name AS 'Writer Name', publisher.name AS " +
        "'Publisher Name', translator.Name AS 'Translator Name', book.year AS 'Year', book.rate AS 'Rate', " +
        "book.vote AS 'Vote' FROM `book`, `fullbook`, `publisher`, `person` AS writer, `person` AS translator " +
        "WHERE (writer.ID = writerID) AND (publisher.ID = publisherID) AND (translator.ID = translatorID) " +
        "AND (book.ID = fullbook.bookID) AND (writerID = " + writerID + ") ";

      } else if(bookID != -1 & writerID == -1 & publisherID != -1) {

        query = "SELECT book.Name AS 'Book Name', writer.name AS 'Writer Name', publisher.name AS " +
        "'Publisher Name', translator.Name AS 'Translator Name', book.year AS 'Year', book.rate AS 'Rate'," +
        "book.vote AS 'Vote' FROM `book`, `fullbook`, `publisher`, `person` AS writer, `person` AS translator " +
        "WHERE (writer.ID = writerID) AND (publisher.ID = publisherID) AND (translator.ID = translatorID) " +
        "AND (book.ID = fullbook.bookID) AND (book.ID = " + bookID + ") " +
        "AND (publisherID = " + publisherID + ")";

      } else if(bookID == -1 & writerID == -1 & publisherID != -1) {

        query = "SELECT book.Name AS 'Book Name', writer.name AS 'Writer Name', publisher.name AS " +
        "'Publisher Name', translator.Name AS 'Translator Name', book.year AS 'Year', book.rate AS 'Rate', " +
        "book.vote AS 'Vote' FROM `book`, `fullbook`, `publisher`, `person` AS writer, `person` AS translator " +
        "WHERE (writer.ID = writerID) AND (publisher.ID = publisherID) AND (translator.ID = translatorID) " +
        "AND (book.ID = fullbook.bookID) AND (publisherID = " + publisherID + ")";

      }

      DataTable table = sql.SelectTable(query);
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
      stringRowInfo.Add("null");//Type

      EditBook eBooks = new EditBook(stringRowInfo,UserID);
      eBooks.MdiParent = ParentForm;
      eBooks.Show();
    }

    private void addBook_Click(object sender,EventArgs e) {
      AddBook aBook = new AddBook();
      aBook.MdiParent = ParentForm;
      aBook.Show();
    }

    private void Refresh_Click(object sender,EventArgs e) {
      DataTable table = sql.SelectTable(query);
      dataGridView1.ReadOnly = true;
      dataGridView1.DataSource = table;
    }
  }
}
