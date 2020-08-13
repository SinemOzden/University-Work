namespace Project {
  partial class ChangePassword {
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
      this.newPass = new System.Windows.Forms.TextBox();
      this.old = new System.Windows.Forms.TextBox();
      this.NewP = new System.Windows.Forms.Label();
      this.Password = new System.Windows.Forms.Label();
      this.ChangePasswordB = new System.Windows.Forms.Button();
      this.newPass2 = new System.Windows.Forms.TextBox();
      this.NP2 = new System.Windows.Forms.Label();
      this.SuspendLayout();
      // 
      // newPass
      // 
      this.newPass.Location = new System.Drawing.Point(49, 202);
      this.newPass.Name = "newPass";
      this.newPass.Size = new System.Drawing.Size(333, 38);
      this.newPass.TabIndex = 10;
      // 
      // old
      // 
      this.old.Location = new System.Drawing.Point(49, 80);
      this.old.Name = "old";
      this.old.Size = new System.Drawing.Size(333, 38);
      this.old.TabIndex = 9;
      // 
      // NewP
      // 
      this.NewP.AutoSize = true;
      this.NewP.Location = new System.Drawing.Point(43, 155);
      this.NewP.Name = "NewP";
      this.NewP.Size = new System.Drawing.Size(202, 32);
      this.NewP.TabIndex = 8;
      this.NewP.Text = "New Password";
      // 
      // Password
      // 
      this.Password.AutoSize = true;
      this.Password.Location = new System.Drawing.Point(42, 33);
      this.Password.Name = "Password";
      this.Password.Size = new System.Drawing.Size(191, 32);
      this.Password.TabIndex = 7;
      this.Password.Text = "Old Password";
      // 
      // ChangePasswordB
      // 
      this.ChangePasswordB.Location = new System.Drawing.Point(265, 382);
      this.ChangePasswordB.Name = "ChangePasswordB";
      this.ChangePasswordB.Size = new System.Drawing.Size(276, 52);
      this.ChangePasswordB.TabIndex = 13;
      this.ChangePasswordB.Text = "Change Password";
      this.ChangePasswordB.UseVisualStyleBackColor = true;
      this.ChangePasswordB.Click += new System.EventHandler(this.ChangePassword_Click);
      // 
      // newPass2
      // 
      this.newPass2.Location = new System.Drawing.Point(48, 311);
      this.newPass2.Name = "newPass2";
      this.newPass2.Size = new System.Drawing.Size(333, 38);
      this.newPass2.TabIndex = 11;
      this.newPass2.KeyDown += new System.Windows.Forms.KeyEventHandler(this.newPass2_KeyDown);
      // 
      // NP2
      // 
      this.NP2.AutoSize = true;
      this.NP2.Location = new System.Drawing.Point(42, 264);
      this.NP2.Name = "NP2";
      this.NP2.Size = new System.Drawing.Size(301, 32);
      this.NP2.TabIndex = 12;
      this.NP2.Text = "New Password (Again)";
      // 
      // ChangePassword
      // 
      this.AutoScaleDimensions = new System.Drawing.SizeF(16F, 31F);
      this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
      this.ClientSize = new System.Drawing.Size(566, 470);
      this.Controls.Add(this.newPass2);
      this.Controls.Add(this.NP2);
      this.Controls.Add(this.ChangePasswordB);
      this.Controls.Add(this.newPass);
      this.Controls.Add(this.old);
      this.Controls.Add(this.NewP);
      this.Controls.Add(this.Password);
      this.Name = "ChangePassword";
      this.Text = "Change Password";
      this.ResumeLayout(false);
      this.PerformLayout();

    }

    #endregion

    private System.Windows.Forms.TextBox newPass;
    private System.Windows.Forms.TextBox old;
    private System.Windows.Forms.Label NewP;
    private System.Windows.Forms.TextBox newPass2;
    private System.Windows.Forms.Label Password;
    private System.Windows.Forms.Button ChangePasswordB;
    private System.Windows.Forms.Label NP2;
  }
}