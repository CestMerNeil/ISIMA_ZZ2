using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace WindowsFormsApp1
{
    class Professeur : Personne
    {
        private String matiere;

        public String getMatiere()
        {
            return this.matiere;
        }

        private void setMatiere(String matiere)
        {
            this.matiere = matiere;
        }

        public Professeur(String nom, String prenom, int age, String matiere) : base(nom, prenom, age)
        {
            setMatiere(matiere);
        }

        public String toString()
        {
            return ((Personne)this).toString() + ", matiere = " + getMatiere();
        }
    }
}
