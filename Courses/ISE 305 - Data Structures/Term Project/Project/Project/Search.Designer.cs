namespace Project {
  partial class Search {
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
      this.label1 = new System.Windows.Forms.Label();
      this.label2 = new System.Windows.Forms.Label();
      this.label3 = new System.Windows.Forms.Label();
      this.BookBox = new System.Windows.Forms.TextBox();
      this.WriterBox = new System.Windows.Forms.TextBox();
      this.PublisherBox = new System.Windows.Forms.TextBox();
      this.SearchB = new System.Windows.Forms.Button();
      this.SuspendLayout();
      // 
      // label1
      // 
      this.label1.AutoSize = true;
      this.label1.Location = new System.Drawing.Point(53, 48);
      this.label1.Name = "label1";
      this.label1.Size = new System.Drawing.Size(80, 32);
      this.label1.TabIndex = 0;
      this.label1.Text = "Book";
      // 
      // label2
      // 
      this.label2.AutoSize = true;
      this.label2.Location = new System.Drawing.Point(53, 138);
      this.label2.Name = "label2";
      this.label2.Size = new System.Drawing.Size(90, 32);
      this.label2.TabIndex = 1;
      this.label2.Text = "Writer";
      // 
      // label3
      // 
      this.label3.AutoSize = true;
      this.label3.Location = new System.Drawing.Point(53, 227);
      this.label3.Name = "label3";
      this.label3.Size = new System.Drawing.Size(135, 32);
      this.label3.TabIndex = 2;
      this.label3.Text = "Publisher";
      // 
      // BookBox
      // 
      this.BookBox.Location = new System.Drawing.Point(260, 42);
      this.BookBox.Name = "BookBox";
      this.BookBox.Size = new System.Drawing.Size(457, 38);
      this.BookBox.TabIndex = 3;
      this.BookBox.KeyDown += new System.Windows.Forms.KeyEventHandler(this.BookBox_KeyDown);
      // 
      // WriterBox
      // 
      this.WriterBox.Location = new System.Drawing.Point(260, 132);
      this.WriterBox.Name = "WriterBox";
      this.WriterBox.Size = new System.Drawing.Size(457, 38);
      this.WriterBox.TabIndex = 4;
      this.WriterBox.KeyDown += new System.Windows.Forms.KeyEventHandler(this.WriterBox_KeyDown);
      // 
      // PublisherBox
      // 
      this.PublisherBox.Location = new System.Drawing.Point(260, 227);
      this.PublisherBox.Name = "PublisherBox";
      this.PublisherBox.Size = new System.Drawing.Size(457, 38);
      this.PublisherBox.TabIndex = 5;
      this.PublisherBox.KeyDown += new System.Windows.Forms.KeyEventHandler(this.PublisherBox_KeyDown);
      // 
      // SearchB
      // 
      this.SearchB.Location = new System.Drawing.Point(501, 298);
      this.SearchB.Name = "SearchB";
      this.SearchB.Size = new System.Drawing.Size(216, 48);
      this.SearchB.TabIndex = 6;
      this.SearchB.Text = "Search";
      this.SearchB.UseVisualStyleBackColor = true;
      this.SearchB.Click += new System.EventHandler(this.SearchB_Click);
      // 
      // Search
      // 
      this.AutoScaleDimensions = new System.Drawing.SizeF(16F, 31F);
      this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
      this.ClientSize = new System.Drawing.Size(795, 379);
      this.Controls.Add(this.SearchB);
      this.Controls.Add(this.PublisherBox);
      this.Controls.Add(this.WriterBox);
      this.Controls.Add(this.BookBox);
      this.Controls.Add(this.label3);
      this.Controls.Add(this.label2);
      this.Controls.Add(this.label1);
      this.Name = "Search";
      this.Text = "Search";
      this.Load += new System.EventHandler(this.Search_Load);
      this.ResumeLayout(false);
      this.PerformLayout();

    }

    #endregion

    private System.Windows.Forms.Label label1;
    private System.Windows.Forms.Label label2;
    private System.Windows.Forms.Label label3;
    private System.Windows.Forms.TextBox BookBox;
    private System.Windows.Forms.TextBox WriterBox;
    private System.Windows.Forms.TextBox PublisherBox;
    private System.Windows.Forms.Button SearchB;
  }
}