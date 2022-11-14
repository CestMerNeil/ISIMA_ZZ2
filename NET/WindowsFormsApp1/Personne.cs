using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace WindowsFormsApp1
{
    class Personne
    {
        private int age;
        private String nom;
        private String prenom;

        public Personne(String nom, String prenom, int age)
        {
            this.age = age;
            this.prenom = prenom;
            this.nom = nom;
        }


        public int getAge()
        {
            return this.age;
        }

        public String getNom() {
            return this.nom;
        }

        public String getPrenom()
        {
            return this.prenom;
        }

        public override String ToString()
        {
            return this.nom + " " + this.prenom + ", " + this.age + " ans";
        }
    }
}
