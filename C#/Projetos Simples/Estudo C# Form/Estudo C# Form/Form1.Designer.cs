namespace Estudo_C__Form
{
    partial class Form1
    {
        /// <summary>
        ///  Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        ///  Clean up any resources being used.
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
        ///  Required method for Designer support - do not modify
        ///  the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            button1 = new Button();
            numericUpDown1 = new NumericUpDown();
            numericUpDown2 = new NumericUpDown();
            label1 = new Label();
            groupBox1 = new GroupBox();
            button2 = new Button();
            ((System.ComponentModel.ISupportInitialize)numericUpDown1).BeginInit();
            ((System.ComponentModel.ISupportInitialize)numericUpDown2).BeginInit();
            groupBox1.SuspendLayout();
            SuspendLayout();
            // 
            // button1
            // 
            button1.BackColor = Color.Black;
            button1.FlatStyle = FlatStyle.Flat;
            button1.ForeColor = Color.White;
            button1.Location = new Point(34, 187);
            button1.Name = "button1";
            button1.Size = new Size(216, 41);
            button1.TabIndex = 0;
            button1.Text = "Resultado";
            button1.UseVisualStyleBackColor = false;
            button1.Click += button1_Click;
            // 
            // numericUpDown1
            // 
            numericUpDown1.Location = new Point(34, 92);
            numericUpDown1.Maximum = new decimal(new int[] { 1410065407, 2, 0, 0 });
            numericUpDown1.Minimum = new decimal(new int[] { 1410065407, 2, 0, int.MinValue });
            numericUpDown1.Name = "numericUpDown1";
            numericUpDown1.Size = new Size(216, 23);
            numericUpDown1.TabIndex = 1;
            numericUpDown1.TextAlign = HorizontalAlignment.Center;
            numericUpDown1.ValueChanged += numericUpDown1_ValueChanged;
            // 
            // numericUpDown2
            // 
            numericUpDown2.Location = new Point(34, 139);
            numericUpDown2.Maximum = new decimal(new int[] { 1410065407, 2, 0, 0 });
            numericUpDown2.Minimum = new decimal(new int[] { 1410065407, 2, 0, int.MinValue });
            numericUpDown2.Name = "numericUpDown2";
            numericUpDown2.Size = new Size(216, 23);
            numericUpDown2.TabIndex = 2;
            numericUpDown2.TextAlign = HorizontalAlignment.Center;
            // 
            // label1
            // 
            label1.BackColor = SystemColors.Window;
            label1.BorderStyle = BorderStyle.Fixed3D;
            label1.Location = new Point(34, 28);
            label1.Name = "label1";
            label1.Size = new Size(216, 42);
            label1.TabIndex = 4;
            label1.TextAlign = ContentAlignment.MiddleCenter;
            label1.Click += label1_Click_1;
            // 
            // groupBox1
            // 
            groupBox1.BackColor = Color.FromArgb(224, 224, 224);
            groupBox1.Controls.Add(button2);
            groupBox1.Controls.Add(label1);
            groupBox1.Controls.Add(numericUpDown2);
            groupBox1.Controls.Add(numericUpDown1);
            groupBox1.Controls.Add(button1);
            groupBox1.FlatStyle = FlatStyle.Popup;
            groupBox1.Location = new Point(246, 28);
            groupBox1.Name = "groupBox1";
            groupBox1.Size = new Size(279, 336);
            groupBox1.TabIndex = 3;
            groupBox1.TabStop = false;
            groupBox1.Enter += groupBox1_Enter;
            // 
            // button2
            // 
            button2.BackColor = Color.Black;
            button2.FlatStyle = FlatStyle.Flat;
            button2.ForeColor = Color.White;
            button2.Location = new Point(34, 245);
            button2.Name = "button2";
            button2.Size = new Size(216, 41);
            button2.TabIndex = 5;
            button2.Text = "Limpar";
            button2.UseVisualStyleBackColor = false;
            button2.Click += button2_Click;
            // 
            // Form1
            // 
            AutoScaleDimensions = new SizeF(7F, 15F);
            AutoScaleMode = AutoScaleMode.Font;
            BackColor = Color.White;
            ClientSize = new Size(800, 450);
            Controls.Add(groupBox1);
            Name = "Form1";
            Text = "Cálculo";
            Load += Form1_Load;
            ((System.ComponentModel.ISupportInitialize)numericUpDown1).EndInit();
            ((System.ComponentModel.ISupportInitialize)numericUpDown2).EndInit();
            groupBox1.ResumeLayout(false);
            ResumeLayout(false);
        }

        #endregion

        private Button button1;
        private NumericUpDown numericUpDown1;
        private NumericUpDown numericUpDown2;
        private Label label1;
        private GroupBox groupBox1;
        private Button button2;
    }
}
