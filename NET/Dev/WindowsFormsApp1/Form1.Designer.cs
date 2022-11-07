
namespace WindowsFormsApp1
{
    partial class Form1
    {
        /// <summary>
        /// Variable nécessaire au concepteur.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Nettoyage des ressources utilisées.
        /// </summary>
        /// <param name="disposing">true si les ressources managées doivent être supprimées ; sinon, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Code généré par le Concepteur Windows Form

        /// <summary>
        /// Méthode requise pour la prise en charge du concepteur - ne modifiez pas
        /// le contenu de cette méthode avec l'éditeur de code.
        /// </summary>
        private void InitializeComponent()
        {
            this.v = new System.ComponentModel.BackgroundWorker();
            this.textBoxNom = new System.Windows.Forms.TextBox();
            this.nom = new System.Windows.Forms.Label();
            this.textBoxPrenom = new System.Windows.Forms.TextBox();
            this.textBoxAge = new System.Windows.Forms.TextBox();
            this.prenom = new System.Windows.Forms.Label();
            this.age = new System.Windows.Forms.Label();
            this.classe = new System.Windows.Forms.Label();
            this.textBoxClasse = new System.Windows.Forms.TextBox();
            this.radioButtonEtudiant = new System.Windows.Forms.RadioButton();
            this.radioButtonProfesseur = new System.Windows.Forms.RadioButton();
            this.buttonEnregistrement = new System.Windows.Forms.Button();
            this.buttonEtudiant = new System.Windows.Forms.Button();
            this.buttonProf = new System.Windows.Forms.Button();
            this.buttonTous = new System.Windows.Forms.Button();
            this.label1 = new System.Windows.Forms.Label();
            this.radioButtonAncien = new System.Windows.Forms.RadioButton();
            this.radioButtonAlpha = new System.Windows.Forms.RadioButton();
            this.radioButtonChrono = new System.Windows.Forms.RadioButton();
            this.splitContainer1 = new System.Windows.Forms.SplitContainer();
            this.groupBox2 = new System.Windows.Forms.GroupBox();
            this.label6 = new System.Windows.Forms.Label();
            this.groupBox1 = new System.Windows.Forms.GroupBox();
            this.richTextBox1 = new System.Windows.Forms.RichTextBox();
            ((System.ComponentModel.ISupportInitialize)(this.splitContainer1)).BeginInit();
            this.splitContainer1.Panel1.SuspendLayout();
            this.splitContainer1.Panel2.SuspendLayout();
            this.splitContainer1.SuspendLayout();
            this.groupBox2.SuspendLayout();
            this.groupBox1.SuspendLayout();
            this.SuspendLayout();
            // 
            // textBoxNom
            // 
            this.textBoxNom.Location = new System.Drawing.Point(97, 119);
            this.textBoxNom.Name = "textBoxNom";
            this.textBoxNom.Size = new System.Drawing.Size(219, 20);
            this.textBoxNom.TabIndex = 1;
            this.textBoxNom.TextChanged += new System.EventHandler(this.textBox1_TextChanged);
            // 
            // nom
            // 
            this.nom.AutoSize = true;
            this.nom.Location = new System.Drawing.Point(37, 119);
            this.nom.Name = "nom";
            this.nom.Size = new System.Drawing.Size(35, 13);
            this.nom.TabIndex = 2;
            this.nom.Text = "Nom :";
            // 
            // textBoxPrenom
            // 
            this.textBoxPrenom.Location = new System.Drawing.Point(499, 152);
            this.textBoxPrenom.Name = "textBoxPrenom";
            this.textBoxPrenom.Size = new System.Drawing.Size(219, 20);
            this.textBoxPrenom.TabIndex = 3;
            // 
            // textBoxAge
            // 
            this.textBoxAge.Location = new System.Drawing.Point(499, 187);
            this.textBoxAge.Name = "textBoxAge";
            this.textBoxAge.Size = new System.Drawing.Size(219, 20);
            this.textBoxAge.TabIndex = 4;
            // 
            // prenom
            // 
            this.prenom.AutoSize = true;
            this.prenom.Location = new System.Drawing.Point(37, 154);
            this.prenom.Name = "prenom";
            this.prenom.Size = new System.Drawing.Size(49, 13);
            this.prenom.TabIndex = 5;
            this.prenom.Text = "Prénom :";
            // 
            // age
            // 
            this.age.AutoSize = true;
            this.age.Location = new System.Drawing.Point(439, 187);
            this.age.Name = "age";
            this.age.Size = new System.Drawing.Size(32, 13);
            this.age.TabIndex = 6;
            this.age.Text = "Age :";
            // 
            // classe
            // 
            this.classe.AutoSize = true;
            this.classe.Location = new System.Drawing.Point(439, 222);
            this.classe.Name = "classe";
            this.classe.Size = new System.Drawing.Size(44, 13);
            this.classe.TabIndex = 8;
            this.classe.Text = "Classe :";
            this.classe.Click += new System.EventHandler(this.classe_Click);
            // 
            // textBoxClasse
            // 
            this.textBoxClasse.Location = new System.Drawing.Point(499, 222);
            this.textBoxClasse.Name = "textBoxClasse";
            this.textBoxClasse.Size = new System.Drawing.Size(219, 20);
            this.textBoxClasse.TabIndex = 7;
            this.textBoxClasse.TextChanged += new System.EventHandler(this.textBoxClasse_TextChanged);
            // 
            // radioButtonEtudiant
            // 
            this.radioButtonEtudiant.AutoSize = true;
            this.radioButtonEtudiant.Location = new System.Drawing.Point(6, 17);
            this.radioButtonEtudiant.Name = "radioButtonEtudiant";
            this.radioButtonEtudiant.Size = new System.Drawing.Size(64, 17);
            this.radioButtonEtudiant.TabIndex = 9;
            this.radioButtonEtudiant.TabStop = true;
            this.radioButtonEtudiant.Text = "Etudiant";
            this.radioButtonEtudiant.UseVisualStyleBackColor = true;
            this.radioButtonEtudiant.CheckedChanged += new System.EventHandler(this.radioButtonEtudiant_CheckedChanged);
            // 
            // radioButtonProfesseur
            // 
            this.radioButtonProfesseur.AutoSize = true;
            this.radioButtonProfesseur.Location = new System.Drawing.Point(90, 17);
            this.radioButtonProfesseur.Name = "radioButtonProfesseur";
            this.radioButtonProfesseur.Size = new System.Drawing.Size(75, 17);
            this.radioButtonProfesseur.TabIndex = 10;
            this.radioButtonProfesseur.TabStop = true;
            this.radioButtonProfesseur.Text = "Professeur";
            this.radioButtonProfesseur.UseVisualStyleBackColor = true;
            this.radioButtonProfesseur.CheckedChanged += new System.EventHandler(this.radioButtonProfesseur_CheckedChanged);
            // 
            // buttonEnregistrement
            // 
            this.buttonEnregistrement.Location = new System.Drawing.Point(116, 387);
            this.buttonEnregistrement.Name = "buttonEnregistrement";
            this.buttonEnregistrement.Size = new System.Drawing.Size(171, 31);
            this.buttonEnregistrement.TabIndex = 11;
            this.buttonEnregistrement.Text = "Enregistrement";
            this.buttonEnregistrement.UseVisualStyleBackColor = true;
            this.buttonEnregistrement.Click += new System.EventHandler(this.button1_Click);
            // 
            // buttonEtudiant
            // 
            this.buttonEtudiant.Location = new System.Drawing.Point(20, 387);
            this.buttonEtudiant.Name = "buttonEtudiant";
            this.buttonEtudiant.Size = new System.Drawing.Size(99, 31);
            this.buttonEtudiant.TabIndex = 19;
            this.buttonEtudiant.Text = "Etudiant";
            this.buttonEtudiant.UseVisualStyleBackColor = true;
            // 
            // buttonProf
            // 
            this.buttonProf.Location = new System.Drawing.Point(159, 387);
            this.buttonProf.Name = "buttonProf";
            this.buttonProf.Size = new System.Drawing.Size(99, 31);
            this.buttonProf.TabIndex = 18;
            this.buttonProf.Text = "Prof";
            this.buttonProf.UseVisualStyleBackColor = true;
            // 
            // buttonTous
            // 
            this.buttonTous.Location = new System.Drawing.Point(283, 387);
            this.buttonTous.Name = "buttonTous";
            this.buttonTous.Size = new System.Drawing.Size(99, 31);
            this.buttonTous.TabIndex = 17;
            this.buttonTous.Text = "Tous";
            this.buttonTous.UseVisualStyleBackColor = true;
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Font = new System.Drawing.Font("Microsoft Sans Serif", 21.75F, System.Drawing.FontStyle.Italic, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label1.Location = new System.Drawing.Point(116, 30);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(176, 33);
            this.label1.TabIndex = 16;
            this.label1.Text = "Informations";
            this.label1.Click += new System.EventHandler(this.label1_Click_1);
            // 
            // radioButtonAncien
            // 
            this.radioButtonAncien.AutoSize = true;
            this.radioButtonAncien.Location = new System.Drawing.Point(105, 19);
            this.radioButtonAncien.Name = "radioButtonAncien";
            this.radioButtonAncien.Size = new System.Drawing.Size(79, 17);
            this.radioButtonAncien.TabIndex = 21;
            this.radioButtonAncien.TabStop = true;
            this.radioButtonAncien.Text = "Ancienneté";
            this.radioButtonAncien.UseVisualStyleBackColor = true;
            // 
            // radioButtonAlpha
            // 
            this.radioButtonAlpha.AutoSize = true;
            this.radioButtonAlpha.Location = new System.Drawing.Point(0, 19);
            this.radioButtonAlpha.Name = "radioButtonAlpha";
            this.radioButtonAlpha.Size = new System.Drawing.Size(87, 17);
            this.radioButtonAlpha.TabIndex = 20;
            this.radioButtonAlpha.TabStop = true;
            this.radioButtonAlpha.Text = "Alphabétique";
            this.radioButtonAlpha.UseVisualStyleBackColor = true;
            // 
            // radioButtonChrono
            // 
            this.radioButtonChrono.AutoSize = true;
            this.radioButtonChrono.Location = new System.Drawing.Point(201, 19);
            this.radioButtonChrono.Name = "radioButtonChrono";
            this.radioButtonChrono.Size = new System.Drawing.Size(93, 17);
            this.radioButtonChrono.TabIndex = 22;
            this.radioButtonChrono.TabStop = true;
            this.radioButtonChrono.Text = "Chronologique";
            this.radioButtonChrono.UseVisualStyleBackColor = true;
            this.radioButtonChrono.CheckedChanged += new System.EventHandler(this.radioButton5_CheckedChanged);
            // 
            // splitContainer1
            // 
            this.splitContainer1.Location = new System.Drawing.Point(-1, -2);
            this.splitContainer1.Name = "splitContainer1";
            // 
            // splitContainer1.Panel1
            // 
            this.splitContainer1.Panel1.Controls.Add(this.richTextBox1);
            this.splitContainer1.Panel1.Controls.Add(this.label1);
            this.splitContainer1.Panel1.Controls.Add(this.buttonTous);
            this.splitContainer1.Panel1.Controls.Add(this.buttonProf);
            this.splitContainer1.Panel1.Controls.Add(this.buttonEtudiant);
            this.splitContainer1.Panel1.Controls.Add(this.groupBox2);
            this.splitContainer1.Panel1.Paint += new System.Windows.Forms.PaintEventHandler(this.splitContainer1_Panel1_Paint);
            // 
            // splitContainer1.Panel2
            // 
            this.splitContainer1.Panel2.Controls.Add(this.label6);
            this.splitContainer1.Panel2.Controls.Add(this.buttonEnregistrement);
            this.splitContainer1.Panel2.Controls.Add(this.prenom);
            this.splitContainer1.Panel2.Controls.Add(this.textBoxNom);
            this.splitContainer1.Panel2.Controls.Add(this.nom);
            this.splitContainer1.Panel2.Controls.Add(this.groupBox1);
            this.splitContainer1.Panel2.Paint += new System.Windows.Forms.PaintEventHandler(this.splitContainer1_Panel2_Paint);
            this.splitContainer1.Size = new System.Drawing.Size(800, 440);
            this.splitContainer1.SplitterDistance = 399;
            this.splitContainer1.TabIndex = 23;
            // 
            // groupBox2
            // 
            this.groupBox2.Controls.Add(this.radioButtonAlpha);
            this.groupBox2.Controls.Add(this.radioButtonChrono);
            this.groupBox2.Controls.Add(this.radioButtonAncien);
            this.groupBox2.Location = new System.Drawing.Point(63, 309);
            this.groupBox2.Name = "groupBox2";
            this.groupBox2.Size = new System.Drawing.Size(300, 50);
            this.groupBox2.TabIndex = 25;
            this.groupBox2.TabStop = false;
            // 
            // label6
            // 
            this.label6.AutoSize = true;
            this.label6.Font = new System.Drawing.Font("Microsoft Sans Serif", 21.75F, System.Drawing.FontStyle.Italic, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label6.Location = new System.Drawing.Point(147, 30);
            this.label6.Name = "label6";
            this.label6.Size = new System.Drawing.Size(95, 33);
            this.label6.TabIndex = 24;
            this.label6.Text = "Saisie";
            this.label6.Click += new System.EventHandler(this.label6_Click);
            // 
            // groupBox1
            // 
            this.groupBox1.Controls.Add(this.radioButtonProfesseur);
            this.groupBox1.Controls.Add(this.radioButtonEtudiant);
            this.groupBox1.Location = new System.Drawing.Point(116, 338);
            this.groupBox1.Name = "groupBox1";
            this.groupBox1.Size = new System.Drawing.Size(171, 43);
            this.groupBox1.TabIndex = 24;
            this.groupBox1.TabStop = false;
            this.groupBox1.Enter += new System.EventHandler(this.groupBox1_Enter);
            // 
            // richTextBox1
            // 
            this.richTextBox1.Location = new System.Drawing.Point(63, 86);
            this.richTextBox1.Name = "richTextBox1";
            this.richTextBox1.ReadOnly = true;
            this.richTextBox1.Size = new System.Drawing.Size(294, 217);
            this.richTextBox1.TabIndex = 26;
            this.richTextBox1.Text = "";
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(800, 450);
            this.Controls.Add(this.classe);
            this.Controls.Add(this.textBoxClasse);
            this.Controls.Add(this.age);
            this.Controls.Add(this.textBoxAge);
            this.Controls.Add(this.textBoxPrenom);
            this.Controls.Add(this.splitContainer1);
            this.Name = "Form1";
            this.Text = "Form1";
            this.splitContainer1.Panel1.ResumeLayout(false);
            this.splitContainer1.Panel1.PerformLayout();
            this.splitContainer1.Panel2.ResumeLayout(false);
            this.splitContainer1.Panel2.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)(this.splitContainer1)).EndInit();
            this.splitContainer1.ResumeLayout(false);
            this.groupBox2.ResumeLayout(false);
            this.groupBox2.PerformLayout();
            this.groupBox1.ResumeLayout(false);
            this.groupBox1.PerformLayout();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.ComponentModel.BackgroundWorker v;
        private System.Windows.Forms.TextBox textBoxNom;
        private System.Windows.Forms.Label nom;
        private System.Windows.Forms.TextBox textBoxPrenom;
        private System.Windows.Forms.TextBox textBoxAge;
        private System.Windows.Forms.Label prenom;
        private System.Windows.Forms.Label age;
        private System.Windows.Forms.Label classe;
        private System.Windows.Forms.TextBox textBoxClasse;
        private System.Windows.Forms.RadioButton radioButtonEtudiant;
        private System.Windows.Forms.RadioButton radioButtonProfesseur;
        private System.Windows.Forms.Button buttonEnregistrement;
        private System.Windows.Forms.Button buttonEtudiant;
        private System.Windows.Forms.Button buttonProf;
        private System.Windows.Forms.Button buttonTous;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.RadioButton radioButtonAncien;
        private System.Windows.Forms.RadioButton radioButtonAlpha;
        private System.Windows.Forms.RadioButton radioButtonChrono;
        private System.Windows.Forms.SplitContainer splitContainer1;
        private System.Windows.Forms.Label label6;
        private System.Windows.Forms.GroupBox groupBox1;
        private System.Windows.Forms.GroupBox groupBox2;
        private System.Windows.Forms.RichTextBox richTextBox1;
    }
}

