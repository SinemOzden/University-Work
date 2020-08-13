namespace Project {
  partial class MyProfile {
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
      this.UserNameNL = new System.Windows.Forms.Label();
      this.eMailNL = new System.Windows.Forms.Label();
      this.ChangePassword = new System.Windows.Forms.Button();
      this.UserName = new System.Windows.Forms.Label();
      this.eMail = new System.Windows.Forms.Label();
      this.SuspendLayout();
      // 
      // UserNameNL
      // 
      this.UserNameNL.AutoSize = true;
      this.UserNameNL.Location = new System.Drawing.Point(40, 23);
      this.UserNameNL.Name = "UserNameNL";
      this.UserNameNL.Size = new System.Drawing.Size(156, 32);
      this.UserNameNL.TabIndex = 0;
      this.UserNameNL.Text = "User Name";
      // 
      // eMailNL
      // 
      this.eMailNL.AutoSize = true;
      this.eMailNL.Location = new System.Drawing.Point(41, 81);
      this.eMailNL.Name = "eMailNL";
      this.eMailNL.Size = new System.Drawing.Size(96, 32);
      this.eMailNL.TabIndex = 1;
      this.eMailNL.Text = "E-Mail";
      // 
      // ChangePassword
      // 
      this.ChangePassword.Location = new System.Drawing.Point(303, 161);
      this.ChangePassword.Name = "ChangePassword";
      this.ChangePassword.Size = new System.Drawing.Size(276, 52);
      this.ChangePassword.TabIndex = 3;
      this.ChangePassword.Text = "Change Password";
      this.ChangePassword.UseVisualStyleBackColor = true;
      this.ChangePassword.Click += new System.EventHandler(this.ChangePassword_Click);
      // 
      // UserName
      // 
      this.UserName.AutoSize = true;
      this.UserName.Location = new System.Drawing.Point(317, 23);
      this.UserName.Name = "UserName";
      this.UserName.Size = new System.Drawing.Size(77, 32);
      this.UserName.TabIndex = 7;
      this.UserName.Text = "label";
      // 
      // eMail
      // 
      this.eMail.AutoSize = true;
      this.eMail.Location = new System.Drawing.Point(317, 81);
      this.eMail.Name = "eMail";
      this.eMail.Size = new System.Drawing.Size(77, 32);
      this.eMail.TabIndex = 8;
      this.eMail.Text = "label";
      // 
      // MyProfile
      // 
      this.AutoScaleDimensions = new System.Drawing.SizeF(16F, 31F);
      this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
      this.ClientSize = new System.Drawing.Size(624, 265);
      this.Controls.Add(this.eMail);
      this.Controls.Add(this.UserName);
      this.Controls.Add(this.ChangePassword);
      this.Controls.Add(this.eMailNL);
      this.Controls.Add(this.UserNameNL);
      this.Name = "MyProfile";
      this.Text = "My Profile";
      this.Load += new System.EventHandler(this.MyProfile_Load);
      this.ResumeLayout(false);
      this.PerformLayout();

    }

    #endregion

    private System.Windows.Forms.Label UserNameNL;
    private System.Windows.Forms.Label eMailNL;
    private System.Windows.Forms.Button ChangePassword;
    private System.Windows.Forms.Label UserName;
    private System.Windows.Forms.Label eMail;
  }
}