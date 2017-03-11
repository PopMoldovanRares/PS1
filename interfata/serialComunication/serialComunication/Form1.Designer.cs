namespace serialComunication
{
    partial class ProiectArduino
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.components = new System.ComponentModel.Container();
            this.serialPort1 = new System.IO.Ports.SerialPort(this.components);
            this.label1 = new System.Windows.Forms.Label();
            this.textBox1 = new System.Windows.Forms.TextBox();
            this.bAprindStinge = new System.Windows.Forms.Button();
            this.bDeschidePort = new System.Windows.Forms.Button();
            this.bInchidePort = new System.Windows.Forms.Button();
            this.textBox2 = new System.Windows.Forms.TextBox();
            this.button1 = new System.Windows.Forms.Button();
            this.SuspendLayout();
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(12, 85);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(75, 26);
            this.label1.TabIndex = 0;
            this.label1.Text = "A - aprinde led\r\nS - stinge led\r\n";
            // 
            // textBox1
            // 
            this.textBox1.Location = new System.Drawing.Point(93, 91);
            this.textBox1.Name = "textBox1";
            this.textBox1.Size = new System.Drawing.Size(92, 20);
            this.textBox1.TabIndex = 1;
            // 
            // bAprindStinge
            // 
            this.bAprindStinge.Location = new System.Drawing.Point(15, 133);
            this.bAprindStinge.Name = "bAprindStinge";
            this.bAprindStinge.Size = new System.Drawing.Size(170, 29);
            this.bAprindStinge.TabIndex = 2;
            this.bAprindStinge.Text = "Trimite Comanda";
            this.bAprindStinge.UseVisualStyleBackColor = true;
            this.bAprindStinge.Click += new System.EventHandler(this.bAprindStinge_Click);
            // 
            // bDeschidePort
            // 
            this.bDeschidePort.Location = new System.Drawing.Point(15, 12);
            this.bDeschidePort.Name = "bDeschidePort";
            this.bDeschidePort.Size = new System.Drawing.Size(170, 23);
            this.bDeschidePort.TabIndex = 3;
            this.bDeschidePort.Text = "Deschide Port";
            this.bDeschidePort.UseVisualStyleBackColor = true;
            this.bDeschidePort.Click += new System.EventHandler(this.bDeschidePort_Click);
            // 
            // bInchidePort
            // 
            this.bInchidePort.Location = new System.Drawing.Point(15, 41);
            this.bInchidePort.Name = "bInchidePort";
            this.bInchidePort.Size = new System.Drawing.Size(170, 23);
            this.bInchidePort.TabIndex = 4;
            this.bInchidePort.Text = "Inchide Port";
            this.bInchidePort.UseVisualStyleBackColor = true;
            this.bInchidePort.Click += new System.EventHandler(this.bInchidePort_Click);
            // 
            // textBox2
            // 
            this.textBox2.Location = new System.Drawing.Point(15, 221);
            this.textBox2.Name = "textBox2";
            this.textBox2.ReadOnly = true;
            this.textBox2.Size = new System.Drawing.Size(170, 20);
            this.textBox2.TabIndex = 5;
            // 
            // button1
            // 
            this.button1.Location = new System.Drawing.Point(15, 168);
            this.button1.Name = "button1";
            this.button1.Size = new System.Drawing.Size(170, 29);
            this.button1.TabIndex = 6;
            this.button1.Text = "Afiseaza temperatura";
            this.button1.UseVisualStyleBackColor = true;
            this.button1.Click += new System.EventHandler(this.button1_Click);
            // 
            // ProiectArduino
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(208, 265);
            this.Controls.Add(this.button1);
            this.Controls.Add(this.textBox2);
            this.Controls.Add(this.bInchidePort);
            this.Controls.Add(this.bDeschidePort);
            this.Controls.Add(this.bAprindStinge);
            this.Controls.Add(this.textBox1);
            this.Controls.Add(this.label1);
            this.Name = "ProiectArduino";
            this.Text = "Proiect Arduino";
            this.Load += new System.EventHandler(this.ProiectArduino_Load);
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.IO.Ports.SerialPort serialPort1;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.TextBox textBox1;
        private System.Windows.Forms.Button bAprindStinge;
        private System.Windows.Forms.Button bDeschidePort;
        private System.Windows.Forms.Button bInchidePort;
        private System.Windows.Forms.TextBox textBox2;
        private System.Windows.Forms.Button button1;
    }
}

