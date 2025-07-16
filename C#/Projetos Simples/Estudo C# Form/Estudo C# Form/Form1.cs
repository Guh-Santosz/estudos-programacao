namespace Estudo_C__Form
{
    public partial class Form1 : Form
    {
       int num1, num2, sum;
        public Form1()
        {
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {

        }

        private void label1_Click(object sender, EventArgs e)
        {

        }

        private void groupBox1_Enter(object sender, EventArgs e)
        {

        }

        private void button1_Click(object sender, EventArgs e)
        {
            num1 = (int)numericUpDown1.Value;
            num2 =(int)numericUpDown2.Value;

            sum = num1 + num2;

            label1.Text = sum.ToString();
        }

        private void label1_Click_1(object sender, EventArgs e)
        {

        }

        private void numericUpDown1_ValueChanged(object sender, EventArgs e)
        {

        }

        private void button2_Click(object sender, EventArgs e)
        {
            label1.Text = " ";
            numericUpDown1.Value = 0;
            numericUpDown2.Value = 0;
        }
    }
}
