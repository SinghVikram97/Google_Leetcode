class Solution
{
public:
  bool checkRecord(string s)
  {

    int countA = 0;
    int prevChar = 'D';
    int countL = 0;

    for (int i = 0; i < s.length(); i++)
    {

      if (s[i] == 'L')
      {
        if (prevChar == 'L')
        {
          countL++;
        }
        else
        {
          countL = 1;
        }
        prevChar = s[i];
      }
      else
      {
        countL = 0;
        if (s[i] == 'A')
        {
          countA++;
        }
        prevChar = s[i];
      }
      if (countA > 1 || countL > 2)
      {
        return false;
      }
    }
    return true;
  }
};