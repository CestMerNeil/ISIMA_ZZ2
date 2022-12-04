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
            liste = new ListePersonne();
            richTextBox1.Text = "Bonjour ! Veuillez saisir des informations";
        }

        private void label1_Click(object sender, EventArgs e)
        {

        }

        private void textBox1_TextChanged(object sender, EventArgs e)
        {
        }

        private void textBoxAge_TextChanged(object sender, EventArgs e)
        {
            if (0 > Int32.Parse(textBoxAge.Text) || (Int32.Parse(textBoxAge.Text) > 100)){
                MessageBox.Show("Bonjour");
            }
        }

        private void button1_Click(object sender, EventArgs e)
        {
            if (textBoxNom.TextLength == 0 || textBoxAge.TextLength == 0 || textBoxClasse.TextLength == 0 || textBoxPrenom.TextLength == 0)
            {
                //display message
                richTextBox1.Text = "Vous avez manqué un champ!";
            }
            //il faut chercher "classe"
            else
            {
                if (radioButtonEtudiant.Checked)
                {
                    liste.ajouter(new Etudiant(textBoxNom.Text, textBoxPrenom.Text, Int32.Parse(textBoxAge.Text), textBoxClasse.Text));
                    richTextBox1.Text = "Saisie etudiant enregistrée.";
                }
                else
                {
                    liste.ajouter(new Professeur(textBoxNom.Text, textBoxPrenom.Text, Int32.Parse(textBoxAge.Text), textBoxClasse.Text));
                    richTextBox1.Text = "Saisie professeur enregistrée.";
                }

                textBoxAge.Clear();
                textBoxClasse.Clear();
                textBoxNom.Clear();
                textBoxPrenom.Clear();

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

        private void buttonEtudiant_Click(object sender, EventArgs e)
        {
            int ordre = 2;
            if (radioButtonAlpha.Checked)
            {
                ordre = 0;
            }
            else if (radioButtonAncien.Checked)
            {
                ordre = 1;
            }
            liste.afficherEtudiants(richTextBox1, ordre);
        }

        private void buttonTous_Click(object sender, EventArgs e)
        {
            int ordre = 2;
            if (radioButtonAlpha.Checked)
            {
                ordre = 0;
            }
            else if (radioButtonAncien.Checked)
            {
                ordre = 1;
            }
            liste.afficher(richTextBox1, ordre);
        }

        private void radioButtonAlpha_CheckedChanged(object sender, EventArgs e)
        {

        }

        private void buttonProf_Click(object sender, EventArgs e)
        {
            int ordre = 2;
            if (radioButtonAlpha.Checked)
            {
                ordre = 0;
            }
            else if (radioButtonAncien.Checked)
            {
                ordre = 1;
            }
            liste.afficherProfesseurs(richTextBox1, ordre);
        }

        private void textBoxAge_TextChanged_1(object sender, EventArgs e)
        {

        }
    }


}
