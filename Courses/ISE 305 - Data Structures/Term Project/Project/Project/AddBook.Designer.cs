namespace Project {
  partial class AddBook {
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
      this.label5 = new System.Windows.Forms.Label();
      this.bN = new System.Windows.Forms.TextBox();
      this.wN = new System.Windows.Forms.TextBox();
      this.tN = new System.Windows.Forms.TextBox();
      this.pN = new System.Windows.Forms.TextBox();
      this.year = new System.Windows.Forms.TextBox();
      this.Save = new System.Windows.Forms.Button();
      this.SuspendLayout();
      // 
      // label1
      // 
      this.label1.AutoSize = true;
      this.label1.Location = new System.Drawing.Point(45, 44);
      this.label1.Name = "label1";
      this.label1.Size = new System.Drawing.Size(170, 32);
      this.label1.TabIndex = 0;
      this.label1.Text = "Book Name:";
      // 
      // label2
      // 
      this.label2.AutoSize = true;
      this.label2.Location = new System.Drawing.Point(45, 127);
      this.label2.Name = "label2";
      this.label2.Size = new System.Drawing.Size(180, 32);
      this.label2.TabIndex = 1;
      this.label2.Text = "Writer Name:";
      // 
      // label3
      // 
      this.label3.AutoSize = true;
      this.label3.Location = new System.Drawing.Point(45, 208);
      this.label3.Name = "label3";
      this.label3.Size = new System.Drawing.Size(225, 32);
      this.label3.TabIndex = 2;
      this.label3.Text = "Publisher Name:";
      // 
      // label4
      // 
      this.label4.AutoSize = true;
      this.label4.Location = new System.Drawing.Point(45, 290);
      this.label4.Name = "label4";
      this.label4.Size = new System.Drawing.Size(233, 32);
      this.label4.TabIndex = 3;
      this.label4.Text = "Translator Name:";
      // 
      // label5
      // 
      this.label5.AutoSize = true;
      this.label5.Location = new System.Drawing.Point(45, 366);
      this.label5.Name = "label5";
      this.label5.Size = new System.Drawing.Size(83, 32);
      this.label5.TabIndex = 4;
      this.label5.Text = "Year:";
      // 
      // bN
      // 
      this.bN.Location = new System.Drawing.Point(354, 38);
      this.bN.Name = "bN";
      this.bN.Size = new System.Drawing.Size(398, 38);
      this.bN.TabIndex = 5;
      // 
      // wN
      // 
      this.wN.Location = new System.Drawing.Point(354, 121);
      this.wN.Name = "wN";
      this.wN.Size = new System.Drawing.Size(398, 38);
      this.wN.TabIndex = 6;
      // 
      // tN
      // 
      this.tN.Location = new System.Drawing.Point(354, 284);
      this.tN.Name = "tN";
      this.tN.Size = new System.Drawing.Size(398, 38);
      this.tN.TabIndex = 8;
      // 
      // pN
      // 
      this.pN.Location = new System.Drawing.Point(354,202);
      this.pN.Name = "pN";
      this.pN.Size = new System.Drawing.Size(398,38);
      this.pN.TabIndex = 7;
      // 
      // year
      // 
      this.year.Location = new System.Drawing.Point(354, 360);
      this.year.Name = "year";
      this.year.Size = new System.Drawing.Size(398, 38);
      this.year.TabIndex = 9;
      // 
      // Save
      // 
      this.Save.Location = new System.Drawing.Point(590, 436);
      this.Save.Name = "Save";
      this.Save.Size = new System.Drawing.Size(162, 49);
      this.Save.TabIndex = 10;
      this.Save.Text = "Save";
      this.Save.UseVisualStyleBackColor = true;
      this.Save.Click += new System.EventHandler(this.Save_Click);
      // 
      // AddBook
      // 
      this.AutoScaleDimensions = new System.Drawing.SizeF(16F, 31F);
      this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
      this.ClientSize = new System.Drawing.Size(800, 516);
      this.Controls.Add(this.Save);
      this.Controls.Add(this.year);
      this.Controls.Add(this.pN);
      this.Controls.Add(this.tN);
      this.Controls.Add(this.wN);
      this.Controls.Add(this.bN);
      this.Controls.Add(this.label5);
      this.Controls.Add(this.label4);
      this.Controls.Add(this.label3);
      this.Controls.Add(this.label2);
      this.Controls.Add(this.label1);
      this.Name = "AddBook";
      this.Text = "AddBook";
      this.Load += new System.EventHandler(this.AddBook_Load);
      this.ResumeLayout(false);
      this.PerformLayout();

    }

    #endregion

    private System.Windows.Forms.Label label1;
    private System.Windows.Forms.Label label2;
    private System.Windows.Forms.Label label3;
    private System.Windows.Forms.Label label4;
    private System.Windows.Forms.Label label5;
    private System.Windows.Forms.TextBox bN;
    private System.Windows.Forms.TextBox wN;
    private System.Windows.Forms.TextBox tN;
    private System.Windows.Forms.TextBox pN;
    private System.Windows.Forms.TextBox year;
    private System.Windows.Forms.Button Save;
  }
}