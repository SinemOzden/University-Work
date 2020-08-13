namespace Project {
  partial class NotUnique {
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
      this.OKButton = new System.Windows.Forms.Button();
      this.SuspendLayout();
      // 
      // label1
      // 
      this.label1.AutoSize = true;
      this.label1.Location = new System.Drawing.Point(84, 56);
      this.label1.Name = "label1";
      this.label1.Size = new System.Drawing.Size(655, 32);
      this.label1.TabIndex = 0;
      this.label1.Text = "The E-Mail or User Name Already Exists Try Again!";
      // 
      // OKButton
      // 
      this.OKButton.Location = new System.Drawing.Point(323, 126);
      this.OKButton.Name = "OKButton";
      this.OKButton.Size = new System.Drawing.Size(143, 42);
      this.OKButton.TabIndex = 1;
      this.OKButton.Text = "OK";
      this.OKButton.UseVisualStyleBackColor = true;
      this.OKButton.Click += new System.EventHandler(this.OKButton_Click);
      // 
      // NotUnique
      // 
      this.AutoScaleDimensions = new System.Drawing.SizeF(16F, 31F);
      this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
      this.ClientSize = new System.Drawing.Size(800, 213);
      this.Controls.Add(this.OKButton);
      this.Controls.Add(this.label1);
      this.Name = "NotUnique";
      this.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen;
      this.Text = "Not Unique";
      this.ResumeLayout(false);
      this.PerformLayout();

    }

    #endregion

    private System.Windows.Forms.Label label1;
    private System.Windows.Forms.Button OKButton;
  }
}