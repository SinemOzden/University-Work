namespace Project {
  partial class EditBook {
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
      this.label4 = new System.Windows.Forms.Label();
      this.WantToRead = new System.Windows.Forms.RadioButton();
      this.NowReading = new System.Windows.Forms.RadioButton();
      this.AlreadyRead = new System.Windows.Forms.RadioButton();
      this.BookName = new System.Windows.Forms.Label();
      this.PublisherName = new System.Windows.Forms.Label();
      this.WriterName = new System.Windows.Forms.Label();
      this.TranslatorName = new System.Windows.Forms.Label();
      this.Save = new System.Windows.Forms.Button();
      this.Delete = new System.Windows.Forms.Button();
      this.label5 = new System.Windows.Forms.Label();
      this.comboBox1 = new System.Windows.Forms.ComboBox();
      this.comment = new System.Windows.Forms.RichTextBox();
      this.label6 = new System.Windows.Forms.Label();
      this.SuspendLayout();
      // 
      // label1
      // 
      this.label1.AutoSize = true;
      this.label1.Location = new System.Drawing.Point(49, 51);
      this.label1.Name = "label1";
      this.label1.Size = new System.Drawing.Size(162, 32);
      this.label1.TabIndex = 0;
      this.label1.Text = "Book Name";
      // 
      // label2
      // 
      this.label2.AutoSize = true;
      this.label2.Location = new System.Drawing.Point(49, 125);
      this.label2.Name = "label2";
      this.label2.Size = new System.Drawing.Size(172, 32);
      this.label2.TabIndex = 1;
      this.label2.Text = "Writer Name";
      // 
      // label3
      // 
      this.label3.AutoSize = true;
      this.label3.Location = new System.Drawing.Point(49, 193);
      this.label3.Name = "label3";
      this.label3.Size = new System.Drawing.Size(217, 32);
      this.label3.TabIndex = 2;
      this.label3.Text = "Publisher Name";
      // 
      // label4
      // 
      this.label4.AutoSize = true;
      this.label4.Location = new System.Drawing.Point(49, 272);
      this.label4.Name = "label4";
      this.label4.Size = new System.Drawing.Size(225, 32);
      this.label4.TabIndex = 3;
      this.label4.Text = "Translator Name";
      // 
      // WantToRead
      // 
      this.WantToRead.AutoSize = true;
      this.WantToRead.Location = new System.Drawing.Point(55, 866);
      this.WantToRead.Name = "WantToRead";
      this.WantToRead.Size = new System.Drawing.Size(224, 36);
      this.WantToRead.TabIndex = 4;
      this.WantToRead.TabStop = true;
      this.WantToRead.Text = "Want to Read";
      this.WantToRead.UseVisualStyleBackColor = true;
      // 
      // NowReading
      // 
      this.NowReading.AutoSize = true;
      this.NowReading.Location = new System.Drawing.Point(329, 866);
      this.NowReading.Name = "NowReading";
      this.NowReading.Size = new System.Drawing.Size(222, 36);
      this.NowReading.TabIndex = 5;
      this.NowReading.TabStop = true;
      this.NowReading.Text = "Now Reading";
      this.NowReading.UseVisualStyleBackColor = true;
      // 
      // AlreadyRead
      // 
      this.AlreadyRead.AutoSize = true;
      this.AlreadyRead.Location = new System.Drawing.Point(586, 866);
      this.AlreadyRead.Name = "AlreadyRead";
      this.AlreadyRead.Size = new System.Drawing.Size(224, 36);
      this.AlreadyRead.TabIndex = 6;
      this.AlreadyRead.TabStop = true;
      this.AlreadyRead.Text = "Already Read";
      this.AlreadyRead.UseVisualStyleBackColor = true;
      // 
      // BookName
      // 
      this.BookName.AutoSize = true;
      this.BookName.Location = new System.Drawing.Point(322, 51);
      this.BookName.Name = "BookName";
      this.BookName.Size = new System.Drawing.Size(93, 32);
      this.BookName.TabIndex = 7;
      this.BookName.Text = "label5";
      // 
      // PublisherName
      // 
      this.PublisherName.AutoSize = true;
      this.PublisherName.Location = new System.Drawing.Point(322, 193);
      this.PublisherName.Name = "PublisherName";
      this.PublisherName.Size = new System.Drawing.Size(93, 32);
      this.PublisherName.TabIndex = 8;
      this.PublisherName.Text = "label6";
      // 
      // WriterName
      // 
      this.WriterName.AutoSize = true;
      this.WriterName.Location = new System.Drawing.Point(322, 125);
      this.WriterName.Name = "WriterName";
      this.WriterName.Size = new System.Drawing.Size(93, 32);
      this.WriterName.TabIndex = 9;
      this.WriterName.Text = "label7";
      // 
      // TranslatorName
      // 
      this.TranslatorName.AutoSize = true;
      this.TranslatorName.Location = new System.Drawing.Point(322, 272);
      this.TranslatorName.Name = "TranslatorName";
      this.TranslatorName.Size = new System.Drawing.Size(93, 32);
      this.TranslatorName.TabIndex = 10;
      this.TranslatorName.Text = "label8";
      // 
      // Save
      // 
      this.Save.Location = new System.Drawing.Point(56, 925);
      this.Save.Name = "Save";
      this.Save.Size = new System.Drawing.Size(282, 61);
      this.Save.TabIndex = 11;
      this.Save.Text = "Save";
      this.Save.UseVisualStyleBackColor = true;
      this.Save.Click += new System.EventHandler(this.Save_Click);
      // 
      // Delete
      // 
      this.Delete.Location = new System.Drawing.Point(528, 925);
      this.Delete.Name = "Delete";
      this.Delete.Size = new System.Drawing.Size(282, 61);
      this.Delete.TabIndex = 12;
      this.Delete.Text = "Delete";
      this.Delete.UseVisualStyleBackColor = true;
      this.Delete.Click += new System.EventHandler(this.Delete_Click);
      // 
      // label5
      // 
      this.label5.AutoSize = true;
      this.label5.Location = new System.Drawing.Point(49, 344);
      this.label5.Name = "label5";
      this.label5.Size = new System.Drawing.Size(75, 32);
      this.label5.TabIndex = 13;
      this.label5.Text = "Rate";
      // 
      // comboBox1
      // 
      this.comboBox1.FormattingEnabled = true;
      this.comboBox1.Items.AddRange(new object[] {
            "0",
            "1",
            "2",
            "3",
            "4",
            "5",
            "6",
            "7",
            "8",
            "9",
            "10"});
      this.comboBox1.Location = new System.Drawing.Point(328, 335);
      this.comboBox1.Name = "comboBox1";
      this.comboBox1.Size = new System.Drawing.Size(121, 39);
      this.comboBox1.TabIndex = 14;
      // 
      // comment
      // 
      this.comment.Location = new System.Drawing.Point(55, 468);
      this.comment.Name = "comment";
      this.comment.Size = new System.Drawing.Size(755, 373);
      this.comment.TabIndex = 15;
      this.comment.Text = "";
      // 
      // label6
      // 
      this.label6.AutoSize = true;
      this.label6.Location = new System.Drawing.Point(50, 412);
      this.label6.Name = "label6";
      this.label6.Size = new System.Drawing.Size(137, 32);
      this.label6.TabIndex = 16;
      this.label6.Text = "Comment";
      // 
      // EditBook
      // 
      this.AutoScaleDimensions = new System.Drawing.SizeF(16F, 31F);
      this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
      this.AutoSize = true;
      this.ClientSize = new System.Drawing.Size(887, 1024);
      this.Controls.Add(this.label6);
      this.Controls.Add(this.comment);
      this.Controls.Add(this.comboBox1);
      this.Controls.Add(this.label5);
      this.Controls.Add(this.Delete);
      this.Controls.Add(this.Save);
      this.Controls.Add(this.TranslatorName);
      this.Controls.Add(this.WriterName);
      this.Controls.Add(this.PublisherName);
      this.Controls.Add(this.BookName);
      this.Controls.Add(this.AlreadyRead);
      this.Controls.Add(this.NowReading);
      this.Controls.Add(this.WantToRead);
      this.Controls.Add(this.label4);
      this.Controls.Add(this.label3);
      this.Controls.Add(this.label2);
      this.Controls.Add(this.label1);
      this.Name = "EditBook";
      this.Text = "EditBook";
      this.Load += new System.EventHandler(this.EditBook_Load);
      this.ResumeLayout(false);
      this.PerformLayout();

    }

    #endregion

    private System.Windows.Forms.Label label1;
    private System.Windows.Forms.Label label2;
    private System.Windows.Forms.Label label3;
    private System.Windows.Forms.Label label4;
    private System.Windows.Forms.RadioButton WantToRead;
    private System.Windows.Forms.RadioButton NowReading;
    private System.Windows.Forms.RadioButton AlreadyRead;
    private System.Windows.Forms.Label BookName;
    private System.Windows.Forms.Label PublisherName;
    private System.Windows.Forms.Label WriterName;
    private System.Windows.Forms.Label TranslatorName;
    private System.Windows.Forms.Button Save;
    private System.Windows.Forms.Button Delete;
    private System.Windows.Forms.Label label5;
    private System.Windows.Forms.ComboBox comboBox1;
    private System.Windows.Forms.RichTextBox comment;
    private System.Windows.Forms.Label label6;
  }
}