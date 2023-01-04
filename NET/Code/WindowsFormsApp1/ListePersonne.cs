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

        public ArrayList getListe()
        {
            return liste;
        }
        public ListePersonne()
        {
            indexAge = new ArrayList(100);
            indexNom = new ArrayList(100);
            liste = new ArrayList(100);
        }
        public void ajouter(Personne nouvelle)
        {
            liste.Add(nouvelle);
            ajoutAge(nouvelle);
            ajoutNom(nouvelle);
        }

        public void ajoutAge(Personne p)
        {
            int i = 0;

            while(indexAge.Count > i && ((Personne)indexAge[i]).getAge() < p.getAge())
            {
                i++;
            }

            indexAge.Insert(i, p);
        }

        public void ajoutNom(Personne p)
        {
            int i = 0;

            while (indexNom.Count > i && 
                ((String.Compare(((Personne)indexNom[i]).getNom(), p.getNom()) < 0) ||
                ((String.Compare(((Personne)indexNom[i]).getNom(), p.getNom()) == 0 && 
                String.Compare(((Personne)indexNom[i]).getPrenom(), p.getPrenom()) < 0))))
            {
                i++;
            }
            indexNom.Insert(i, p);
        }

        public void afficher(RichTextBox debug, int ordre)
        {
            debug.Clear();
            switch (ordre)
            {
                case 0:
                    foreach (Personne p in indexNom)
                    {
                        debug.AppendText(p.ToString() + "\n");
                    }
                    break;
                case 1:
                    foreach (Personne p in indexAge)
                    {
                        debug.AppendText(p.ToString() + "\n");
                    }
                    break;
                case 2:
                    foreach (Personne p in liste)
                    {
                        debug.AppendText(p.ToString() + "\n");
                    }
                    break;
            }
        }

        public void afficherEtudiants(RichTextBox debug, int ordre)
        {
            debug.Clear();
            switch (ordre)
            {
                case 0:
                    foreach (Personne p in indexNom)
                    {
                        if (typeof(Etudiant).IsInstanceOfType(p))
                        {
                            debug.AppendText(p.ToString() + "\n");
                        }
                    }
                    break;
                case 1:
                    foreach (Personne p in indexAge)
                    {
                        if (typeof(Etudiant).IsInstanceOfType(p))
                        {
                            debug.AppendText(p.ToString() + "\n");
                        }
                    }
                    break;
                case 2:
                    foreach (Personne p in liste)
                    {
                        if (typeof(Etudiant).IsInstanceOfType(p))
                        {
                            debug.AppendText(p.ToString() + "\n");
                        }
                    }
                    break;
            }
        }


        public void afficherProfesseurs(RichTextBox debug, int ordre)
        {
            debug.Clear();
            switch (ordre)
            {
                case 0:
                    foreach (Personne p in indexNom)
                    {
                        if (typeof(Professeur).IsInstanceOfType(p))
                        {
                            debug.AppendText(p.ToString() + "\n");
                        }
                    }
                    break;
                case 1:
                    foreach (Personne p in indexAge)
                    {
                        if (typeof(Professeur).IsInstanceOfType(p))
                        {
                            debug.AppendText(p.ToString() + "\n");
                        }
                    }
                    break;
                case 2:
                    foreach (Personne p in liste)
                    {
                        if (typeof(Professeur).IsInstanceOfType(p))
                        {
                            debug.AppendText(p.ToString() + "\n");
                        }
                    }
                    break;
            }
        }
    }
}
