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
  public partial class AreYouSure : Form {

    private string bookName;
    
    public static bool ReturnValue1 { get; set; }

    public AreYouSure(string bookN) {
      InitializeComponent();
      bookName = bookN;
    }

    private void AreYouSure_Load(object sender,EventArgs e) {
      label2.Text = bookName + " will be deleted from your list.";
    }

    private void Yes_Click(object sender,EventArgs e) {
      this.DialogResult = DialogResult.OK;
      ReturnValue1 = true;
    }

    private void No_Click(object sender,EventArgs e) {
      this.DialogResult = DialogResult.OK;
      ReturnValue1 = false;
    }
  }
}
