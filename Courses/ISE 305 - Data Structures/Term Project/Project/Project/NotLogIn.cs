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
  public partial class NotLogIn : Form {
    public NotLogIn() {
      InitializeComponent();
    }

    private void OK_Click(object sender,EventArgs e) {
      this.Close();
    }
  }
}
