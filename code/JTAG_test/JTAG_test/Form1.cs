using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace JTAG_test
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
            serialPort1.Open();
            
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            string incomeString = serialPort1.ReadExisting();
            setText(incomeString);
        }

        private void RESETbtn_Click(object sender, EventArgs e)
        {
            //Send Command to the Test Reset position
         
            serialPort1.Write("R");
            string incomeString = serialPort1.ReadExisting();
            setText(incomeString);
            
        }

        private void LOADbtn_Click(object sender, EventArgs e)
        {
            //Load instrution to extest
          
            serialPort1.Write("E");
            string incomeString = serialPort1.ReadExisting();
            setText(incomeString);
         
        }

        private void SENDbtn_Click(object sender, EventArgs e)
        {
            //send test data to do the extest 
            serialPort1.Write("S");
            string incomeString = serialPort1.ReadExisting();
            setText(incomeString);
        }

        private void collectbtn_Click(object sender, EventArgs e)
        {
            //collect data from the extest
           
            serialPort1.Write("O");
            string incomeString = serialPort1.ReadExisting();
            setText(incomeString);
        }

        private void setText(string val)
        {
            textBox3.Text = val;
        
        }

        private void IRcountBtn_Click(object sender, EventArgs e)
        {
            serialPort1.Write("Q");
            String m1 = "x" + textBox1.Text;
            serialPort1.Write(m1);
            string incomeString = serialPort1.ReadExisting();
            setText(incomeString);
            


        }

        private void DRcountBtn_Click(object sender, EventArgs e)
        {
            serialPort1.Write("W");
            String n1 = "q" + textBox2.Text;
            serialPort1.Write(n1);
            string incomeString = serialPort1.ReadExisting();
            setText(incomeString);
            

        }

        private void button1_Click(object sender, EventArgs e)
        {
            string incomeString = serialPort1.ReadExisting();
            setText(incomeString);
        }

        private void textBox3_TextChanged(object sender, EventArgs e)
        {
           
        }

        private void button2_Click(object sender, EventArgs e)
        {
            //collect data from the extest
            serialPort1.Write("I");
            string incomeString = serialPort1.ReadExisting();
            setText(incomeString);
        }

        private void button3_Click(object sender, EventArgs e)
        {
            //collect data from the extest
            serialPort1.Write("D");
            string incomeString = serialPort1.ReadExisting();
            setText(incomeString);
        }

        private void button4_Click(object sender, EventArgs e)
        {
            serialPort1.Write("P");
            string incomeString = serialPort1.ReadExisting();
            setText(incomeString);
        }

        private void button5_Click(object sender, EventArgs e)
        {
            serialPort1.Write("s");
            string incomeString = serialPort1.ReadExisting();
            setText(incomeString);
        }

        private void timer1_Tick(object sender, EventArgs e)
        {
            string incomeString = serialPort1.ReadExisting();
            setText(incomeString);

        }

        private void progressBar1_Click(object sender, EventArgs e)
        {

        }
    }
}
