using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace WindowsFormsApp1
{
    class ListePersonne
    {
        private ArrayList indexAge;
        private ArrayList indexNom;
        private ArrayList liste;

        public void ajouter(Personne nouvelle)
        {
            liste.Add(nouvelle);
        }

        public void afficher(TextBox debug, int ordre)
        {
            debug.Clear();
            foreach(Personne p in liste)
            {
                debug.AppendText(p.toString() + "\n");
            }
        }
    }
}
