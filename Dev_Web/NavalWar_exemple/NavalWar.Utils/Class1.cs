namespace NavalWar.Utils
{
    public static class Utils
    {
        public static List<List<string>> ToListArray(this string[,] array)
        {
            List<List<string>> response = new List<List<string>>();
            for (int i = 0; i < 9; i++)
            {
                response.Add(new List<string>());
                for (int j = 0; j < 9; j++)
                {
                    response[i].Add(array[i,j]);
                }
            }
            return response;
        }
    }
}