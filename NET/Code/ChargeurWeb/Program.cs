using System.Collections;
using System.Net;
using System.Text.RegularExpressions;
using System.Text;
using System.Xml;
using System.Diagnostics.Contracts;
using System.Runtime.CompilerServices;
using System.Collections.Specialized;
using System.Reflection;

public class ChargeurWeb
{
    public static void get(string URL)
    {
        HttpWebRequest hwReq = (HttpWebRequest)WebRequest.Create(URL);
        hwReq.Method = "GET";
        hwReq.KeepAlive = false;

        HttpWebResponse hwRep = (HttpWebResponse)hwReq.GetResponse();
        if (hwRep.StatusCode != HttpStatusCode.OK)
        {
            return;
        }
        using (StreamReader sr = new StreamReader(hwRep.GetResponseStream()))
        {
            Console.WriteLine(sr.ReadToEnd());
        }
    }

    public static ArrayList GetHyperLinks(string htmlCode)
    {
        ArrayList al = new ArrayList();

        string strRegex = @"http://([\w-]+\.)+[\w-]+(/[\w- ./?%&=]*)?";

        Regex r = new Regex(strRegex, RegexOptions.IgnoreCase);
        MatchCollection m = r.Matches(htmlCode);

        for (int i = 0; i <= m.Count - 1; i++)
        {
            bool rep = false;
            string strNew = m[i].ToString();
 
            foreach (string str in al)
            {
                if (strNew == str)
                {
                    rep = true;
                    break;
                }
            }

            if (!rep) al.Add(strNew);
        }
        al.Sort();

        return al;
    }

    static string GetDomain(string strURL)
    {
        string retVal;

        string strRegex = @"(\.com/|\.net/|\.cn/|\.org/|\.gov/)";

        Regex r = new Regex(strRegex, RegexOptions.IgnoreCase);
        Match m = r.Match(strURL);
        retVal = m.ToString();

        strRegex = @"\.|/$";
        retVal = Regex.Replace(retVal, strRegex, "").ToString();

        if (retVal == "")
            retVal = "other";

        return retVal;
    }

    public static void Main(String[] args)
    {
        string URL = "https://aoxie.art";
        get(URL);
    }

}