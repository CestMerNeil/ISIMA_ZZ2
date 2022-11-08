using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace WindowsFormsApp1
{
    public partial class Form1 : Form
    {

        private ListePersonne liste;
        public Form1()
        {
            InitializeComponent();
            radioButtonEtudiant.Checked = true;
            radioButtonAlpha.Checked = true;
            
        }

        private void label1_Click(object sender, EventArgs e)
        {

        }

        private void textBox1_TextChanged(object sender, EventArgs e)
        {
            MessageBox.Show("Bonjour");
        }

        private void button1_Click(object sender, EventArgs e)
        {
            if (textBoxNom.TextLength == 0 || textBoxAge.TextLength == 0 || textBoxClasse.TextLength == 0 || textBoxPrenom.TextLength == 0)
            {
                //display message
                richTextBox1.Text = "you halqjflqijfem";
            }
            //il faut chercher "classe"
            else
            {
                if (radioButtonEtudiant.Checked)
                {
                    Etudiant new = new Etudiant(textBoxNom.Text, textBoxPrenom.Text, textBoxAge.Text, textBoxClasse.Text);
                }
                else
                {

                }
            }
        }

        private void radioButton5_CheckedChanged(object sender, EventArgs e)
        {

        }

        private void splitContainer1_Panel2_Paint(object sender, PaintEventArgs e)
        {

        }

        private void splitContainer1_Panel1_Paint(object sender, PaintEventArgs e)
        {

        }

        private void textBox5_TextChanged(object sender, EventArgs e)
        {

        }

        private void label6_Click(object sender, EventArgs e)
        {

        }

        private void label1_Click_1(object sender, EventArgs e)
        {

        }

        private void groupBox1_Enter(object sender, EventArgs e)
        {

        }

        private void radioButtonEtudiant_CheckedChanged(object sender, EventArgs e)
        {
            if (radioButtonEtudiant.Checked)
            {
                classe.Text = "Classe : ";
            }
            
        }

        private void textBoxClasse_TextChanged(object sender, EventArgs e)
        {

        }

        private void classe_Click(object sender, EventArgs e)
        {

        }

        private void radioButtonProfesseur_CheckedChanged(object sender, EventArgs e)
        {
            if (radioButtonProfesseur.Checked)
            {
                classe.Text = "Matiere : ";
            }
        }

        private void richTextBox1_TextChanged(object sender, EventArgs e)
        {
            
        }
    }


}
