#pragma once

#include <iostream>
#include <cstdlib>
#include <string>
#include "clsDate.h";
#include "clsPeriod.h";

class clsUtil
{
public:

    enum enCharType
    {
        SmallLetter = 1,
        CapitalLetter = 2,
        SpecialChar = 3,
        MixChars = 4,
        Digit = 5
    };

    static void Srand()
    {
        srand((unsigned)time(NULL));
    }

    static int RandomNumber(int From, int To)
    {
        int RandNum = rand() % (To - From + 1) + From;

        return RandNum;
    }

    static void Swap(int& A, int& B)
    {
        int Temp;

        Temp = B;
        B = A;
        A = Temp;
    }

    static void Swap(double& A, double& B)
    {
        double Temp;

        Temp = B;
        B = A;
        A = Temp;
    }

    static void Swap(string& A, string& B)
    {
        string Temp;

        Temp = B;
        B = A;
        A = Temp;
    }

    static void ShuffleArray(int Array[100], int End)
    {
        for (int i = 0; i < End; i++)
        {
            Swap(Array[RandomNumber(0, End - 1)], Array[RandomNumber(0, End - 1)]);
        }
    }
    
    static void ShuffleArray(string Array[100], int End)
    {
        for (int i = 0; i < End; i++)
        {
            Swap(Array[RandomNumber(0, End - 1)], Array[RandomNumber(0, End - 1)]);
        }
    }

    static string Tabs(short NumberOfTabs)
    {
        string t = "";
        for (int i = 1; i < NumberOfTabs; i++)
        {
            t = t + "\t";
            cout << t;
        }
        return t;
    }

    static char GetRandomCharacter(enCharType Check)
    {
        char Charcter;

        switch (Check)
        {
        case enCharType::SmallLetter:
            Charcter = char(RandomNumber(97, 122));
            break;
        case enCharType::CapitalLetter:
            Charcter = char(RandomNumber(65, 90));
            break;
        case enCharType::SpecialChar:
            Charcter = char(RandomNumber(33, 47));
            break;
        case enCharType::Digit:
            Charcter = char(RandomNumber(48, 57));
            break;
        case enCharType::MixChars:
        {
            int randomType = RandomNumber(1, 3);
            switch (randomType)
            {
            case 1: // SmallLetter
                Charcter = char(RandomNumber(97, 122));
                break;
            case 2: // CapitalLetter
                Charcter = char(RandomNumber(65, 90));
                break;
            case 3: // Digit
                Charcter = char(RandomNumber(48, 57));
                break;
            }
            break;
        }

        default:
            Charcter = char(RandomNumber(97, 122));
            break;
        }

        return Charcter;
    }

    static string GenerateAWord(enCharType Char, int length)
    {
        string Word = "";

        for (int i = 0; i < length; i++)
        {
            Word += GetRandomCharacter(Char);
        }
        return Word;
    }

    static string GenerateKey(enCharType Char)
    {
        string Key = "";

        enCharType WordType;

        Key += GenerateAWord(Char, 4) + '-';
        Key += GenerateAWord(Char, 4) + '-';
        Key += GenerateAWord(Char, 4) + '-';
        Key += GenerateAWord(Char, 4);

        return Key;
    }

    static void GenerateKeys(int Num, enCharType Char)
    {
        for (int i = 1; i <= Num; i++)
        {
            cout << "Key [" << i << "] : " << GenerateKey(Char) << endl;
        }
    }

    static void Swap(clsDate Date1, clsDate Date2)
    {
        clsDate::SwapDates(Date1, Date2);
    }

    static void FillArrayWithRandomNumbers(int Array[100], int Length, int Start, int End)
    {
        for (int i = 0; i < Length; i++)
        {
            int CurrentNum = RandomNumber(Start, End);
            Array[i] = CurrentNum;
        }
    }

    static void FillArrayWithRandomWords(string Array[100], int Length, enCharType Char, int NumChars = 4)
    {
        for (int i = 0; i < Length; i++)
        {
            string CurrentWord = GenerateAWord(Char,NumChars);
            Array[i] = CurrentWord;
        }
    }

    static void FillArrayWithRandomKeys(string Array[100], int Length, enCharType Char)
    {
        for (int i = 0; i < Length; i++)
        {
            string CurrentWord = GenerateKey(Char);
            Array[i] = CurrentWord;
        }
    }

  static  bool EncryptionOrDecryption(int Num)
    {
        if (Num == 1)
            return true;
        else
            return false;
    }
  static  string EncryptText(string Text, short EncryptionKey)
    {

        for (int i = 0; i < Text.length(); i++)
        {
            Text[i] = char((int)Text[i] + EncryptionKey);

        }
        return Text;

    }

   static string DecryptText(string EncryptedText, short EncryptionKey)
    {
        for (int i = 0; i < EncryptedText.length(); i++)
        {
            EncryptedText[i] = char((int)EncryptedText[i] - EncryptionKey);
        }
            return EncryptedText;
    }


    static string NumberToText(int Number)
    {

        if (Number == 0)
        {
            return "";
        }

        if (Number >= 1 && Number <= 19)
        {
            string arr[] = { "", "One","Two","Three","Four","Five","Six","Seven",
        "Eight","Nine","Ten","Eleven","Twelve","Thirteen","Fourteen",
          "Fifteen","Sixteen","Seventeen","Eighteen","Nineteen" };

            return  arr[Number] + " ";

        }

        if (Number >= 20 && Number <= 99)
        {
            string arr[] = { "","","Twenty","Thirty","Forty","Fifty","Sixty","Seventy","Eighty","Ninety" };
            return  arr[Number / 10] + " " + NumberToText(Number % 10);
        }

        if (Number >= 100 && Number <= 199)
        {
            return  "One Hundred " + NumberToText(Number % 100);
        }

        if (Number >= 200 && Number <= 999)
        {
            return   NumberToText(Number / 100) + "Hundreds " + NumberToText(Number % 100);
        }

        if (Number >= 1000 && Number <= 1999)
        {
            return  "One Thousand " + NumberToText(Number % 1000);
        }

        if (Number >= 2000 && Number <= 999999)
        {
            return   NumberToText(Number / 1000) + "Thousands " + NumberToText(Number % 1000);
        }

        if (Number >= 1000000 && Number <= 1999999)
        {
            return  "One Million " + NumberToText(Number % 1000000);
        }

        if (Number >= 2000000 && Number <= 999999999)
        {
            return   NumberToText(Number / 1000000) + "Millions " + NumberToText(Number % 1000000);
        }

        if (Number >= 1000000000 && Number <= 1999999999)
        {
            return  "One Billion " + NumberToText(Number % 1000000000);
        }
        else
        {
            return   NumberToText(Number / 1000000000) + "Billions " + NumberToText(Number % 1000000000);
        }


    }




};

