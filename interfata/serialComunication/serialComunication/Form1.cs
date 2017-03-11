using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace serialComunication
{
    public partial class ProiectArduino : Form
    {
        public ProiectArduino()
        {
            InitializeComponent();
            /** Setarea numelui 
             * si a vitezei de transmisie a datelor
             */
            serialPort1.PortName = "COM5";
            serialPort1.BaudRate = 9600;
        }

        private void ProiectArduino_Load(object sender, EventArgs e)
        {

        }

        private void bDeschidePort_Click(object sender, EventArgs e)
        {
            try
            {
                serialPort1.Open();
            }
            catch
            {
                MessageBox.Show("Portul este deschis");
            }
        }

        private void bInchidePort_Click(object sender, EventArgs e)
        {
            serialPort1.Close();
        }

        private void serialPort1_DataReceived(object sender, System.IO.Ports.SerialDataReceivedEventArgs e)
        {
            String RxData = String.Empty;
            RxData = serialPort1.ReadExisting();
            
        }

        private void bAprindStinge_Click(object sender, EventArgs e)
        {
            string aprindeLed = "A";
            string stingeLed = "S";

            try
            {
                serialPort1.Open();
            }
            catch
            {
                if (textBox1.Text == aprindeLed)
                {
                    serialPort1.Write(aprindeLed);
                }
                if (textBox1.Text == stingeLed)
                {
                    serialPort1.Write(stingeLed);
                }
               else if (textBox1.Text != "A" && textBox1.Text != "S")
               {
                    MessageBox.Show("A - aprinde led, iar S - stinge led");
               }
                textBox1.Text = "";
            }
            
           
        }

        private void label2_Click(object sender, EventArgs e)
        {

        }

        private void button1_Click(object sender, EventArgs e)
        {
            serialPort1.Write(" ");
            textBox2.Text = serialPort1.ReadExisting();
        }
    }
}
