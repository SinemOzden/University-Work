namespace Project {
  partial class MainPage {
    /// <summary>
    /// Required designer variable.
    /// </summary>
    private System.ComponentModel.IContainer components = null;

    /// <summary>
    /// Clean up any resources being used.
    /// </summary>
    /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
    protected override void Dispose(bool disposing) {
      if(disposing && (components != null)) {
        components.Dispose();
      }
      base.Dispose(disposing);
    }

    #region Windows Form Designer generated code

    /// <summary>
    /// Required method for Designer support - do not modify
    /// the contents of this method with the code editor.
    /// </summary>
    private void InitializeComponent() {
      System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(MainPage));
      this.toolStrip1 = new System.Windows.Forms.ToolStrip();
      this.MyProfileButton = new System.Windows.Forms.ToolStripButton();
      this.MyBooksButton = new System.Windows.Forms.ToolStripButton();
      this.Hello = new System.Windows.Forms.ToolStripLabel();
      this.Books = new System.Windows.Forms.ToolStripButton();
      this.LogIn = new System.Windows.Forms.ToolStripButton();
      this.toolStrip1.SuspendLayout();
      this.SuspendLayout();
      // 
      // toolStrip1
      // 
      this.toolStrip1.ImageScalingSize = new System.Drawing.Size(40, 40);
      this.toolStrip1.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.MyProfileButton,
            this.MyBooksButton,
            this.Hello,
            this.Books,
            this.LogIn});
      this.toolStrip1.Location = new System.Drawing.Point(0, 0);
      this.toolStrip1.Name = "toolStrip1";
      this.toolStrip1.Size = new System.Drawing.Size(1902, 48);
      this.toolStrip1.TabIndex = 1;
      this.toolStrip1.Text = "toolStrip1";
      // 
      // MyProfileButton
      // 
      this.MyProfileButton.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Text;
      this.MyProfileButton.Image = ((System.Drawing.Image)(resources.GetObject("MyProfileButton.Image")));
      this.MyProfileButton.ImageTransparentColor = System.Drawing.Color.Magenta;
      this.MyProfileButton.Name = "MyProfileButton";
      this.MyProfileButton.Size = new System.Drawing.Size(156, 45);
      this.MyProfileButton.Text = "My Profile";
      this.MyProfileButton.Click += new System.EventHandler(this.MyProfileButton_Click);
      // 
      // MyBooksButton
      // 
      this.MyBooksButton.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Text;
      this.MyBooksButton.Image = ((System.Drawing.Image)(resources.GetObject("MyBooksButton.Image")));
      this.MyBooksButton.ImageTransparentColor = System.Drawing.Color.Magenta;
      this.MyBooksButton.Name = "MyBooksButton";
      this.MyBooksButton.Size = new System.Drawing.Size(153, 45);
      this.MyBooksButton.Text = "My Books";
      this.MyBooksButton.Click += new System.EventHandler(this.MyBooksButton_Click);
      // 
      // Hello
      // 
      this.Hello.Alignment = System.Windows.Forms.ToolStripItemAlignment.Right;
      this.Hello.Name = "Hello";
      this.Hello.Size = new System.Drawing.Size(87, 45);
      this.Hello.Text = "Hello";
      // 
      // Books
      // 
      this.Books.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Text;
      this.Books.Image = ((System.Drawing.Image)(resources.GetObject("Books.Image")));
      this.Books.ImageTransparentColor = System.Drawing.Color.Magenta;
      this.Books.Name = "Books";
      this.Books.Size = new System.Drawing.Size(103, 45);
      this.Books.Text = "Books";
      this.Books.Click += new System.EventHandler(this.Books_Click);
      // 
      // LogIn
      // 
      this.LogIn.Alignment = System.Windows.Forms.ToolStripItemAlignment.Right;
      this.LogIn.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Text;
      this.LogIn.Image = ((System.Drawing.Image)(resources.GetObject("LogIn.Image")));
      this.LogIn.ImageTransparentColor = System.Drawing.Color.Magenta;
      this.LogIn.Name = "LogIn";
      this.LogIn.Size = new System.Drawing.Size(105, 45);
      this.LogIn.Text = "Log In";
      this.LogIn.Click += new System.EventHandler(this.LogIn_Click);
      // 
      // MainPage
      // 
      this.AutoScaleDimensions = new System.Drawing.SizeF(16F, 31F);
      this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
      this.ClientSize = new System.Drawing.Size(1902, 1183);
      this.Controls.Add(this.toolStrip1);
      this.IsMdiContainer = true;
      this.Name = "MainPage";
      this.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen;
      this.Text = "ATHSHE";
      this.WindowState = System.Windows.Forms.FormWindowState.Maximized;
      this.Load += new System.EventHandler(this.MainPage_Load);
      this.toolStrip1.ResumeLayout(false);
      this.toolStrip1.PerformLayout();
      this.ResumeLayout(false);
      this.PerformLayout();

    }

    #endregion
    private System.Windows.Forms.ToolStrip toolStrip1;
    private System.Windows.Forms.ToolStripButton MyBooksButton;
    private System.Windows.Forms.ToolStripButton MyProfileButton;
    private System.Windows.Forms.ToolStripLabel Hello;
    private System.Windows.Forms.ToolStripButton Books;
    private System.Windows.Forms.ToolStripButton LogIn;
  }
}