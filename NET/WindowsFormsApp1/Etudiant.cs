using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace WindowsFormsApp1
{
    class Etudiant : Personne
    {
        private String classe;

        public String getClasse()
        {
            return this.classe;
        }

        private void setClasse(String classe)
        {
            this.classe = classe;
        }

        public Etudiant(String nom, String prenom, int age, String classe) : base(nom, prenom, age)
        {
            setClasse(classe);
        }

        public String toString()
        {
            return ((Personne) this).toString() + ", classe = " + getClasse();
        }
    }
}
