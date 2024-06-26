#include <iostream>
#include <string.h>
#include <fstream>
#include <stdlib.h>

using namespace std;

static int InsertSpacesWithBackslash(char *out,char *in)
{
    int inLen = strlen(in);

    out[0] = in[0];
    int j = 1;
    for (int i = 1; i < inLen; i++,j++)
    {
        if(i%2 == 0)
        {
            out[j] = 0x20;
            j++;
            if(i%60 == 0)
            {
                out[j] = 0x5C;
                j++;
                out[j] = 0x0D;
                j++;
                out[j] = 0x0A;
                j++;
            }
        }
        out[j] = in[i];
    }
    return j;
}


static int InsertSpacesNoBackslash(char *out,char *in)
{
    int inLen = strlen(in);

    out[0] = in[0];
    int j = 1;
    for (int i = 1; i < inLen; i++,j++)
    {
        if(i%2 == 0)
        {
            out[j] = 0x20;
            j++;
/*            if(i%60 == 0)
            {
                out[j] = 0x5C;
                j++;
                out[j] = 0x0D;
                j++;
                out[j] = 0x0A;
                j++;
            }*/
        }
        out[j] = in[i];
    }
    return j;
}

char intToAscii(int number)
{
   return '0' + number;
}

int main()
{
    char* hexArray[]=
    {
    "2E7201523032333241524E480600007F04000040000000000000000000000040000000000000000000000000000040000000000000000000000000000040000000000000000000000000000040000000000000000000007F0600000200000000007F120000040000000D020000FF120000020000000003FF1300007000000085B229000000682135132CE1000000685D7E923EC1889E4098A281E6223E00000000000000004000000000000069A87E923EC1D4F0409757819AD03DA2B832BD8EDACB9E415E47CD7CD223000000000000000040000000000000000000000000000040000000000000000000000000007F2200000400000000000000FF220000020000000004FF23000070000000E31B31000000D55A44F33ED300000014B17CFA43C3013340EC4E8305893CB3EF680402D51B48414D1097E1B529890850D9D0CE5A0E4377F7AFD1202E000000000000000040000000000000000000000000000040000000000000000000000000000040000000000000000000000000007F320000040000000D020000FF320000020000000003FF3300007000000085B229000000682135132CE1000000685D7E923EC1889E4098A281E6223E00000000000000004000000000000069A87E923EC1D4F0409757819AD03DA2B832BD8EDACB9E415E47CD7CD223000000000000000040000000000000000000000000000040000000000000000000000000007F4200000400000000000000FF420000020000000004FF43000070000000E31B31000000D55A44F33ED300000014B17CFA43C3013340EC4E8305893CB3EF680402D51B48414D1097E1B529890850D9D0CE5A0E4377F7AFD1202E000000000000000040000000000000000000000000000040000000000000000000000000000040000000000000000000000000007F75000006000000010018FCECFFFF7500000200000002007F760000020000000C007F0300004000000000000000000000004000000000000000000000000000004000000000000000000000000000004000000000000000000000000000004000000000000000000000FF0400004000000000000000000000004000000000000000000000000000004000000000000000000000000000004000000000000000000000000000004000000000000000000000FF0100002E02000000000000000000000040000000000000000001874D7E66A7C114774279B28186E13B000C02874D7E66A7C114774279B28186E13B000C03874D7E66A7C114774279B28186E13B000C04874D7E66A7C16D1B4279B2812D3D3C000B05874D7E66A7C1BCC94179B281DE8E3C000A06874D7E66A7C1F1804179B281A9D73C000907874D7E66A7C10F404179B2818B183D000808874D7E66A7C139064179B28160523D000709874D7E66A7C1B2D24079B281EC853D00060A874D7E66A7C1C1A44079B281D8B33D00050B874D7E66A7C1D07B4079B281CADC3D00040C874D7E66A7C153574079B28147013E00030D874D7E66A7C1D2364079B281CC213E00020E874D7E66A7C1D2364079B281CC213E00020F874D7E66A7C1D6194079B281C83E3E000110874D7E66A7C1D6194079B281C83E3E00011100000000000000004000000000000000001200000000000000004000000000000000001300000000000000004000000000000000001400000000000000004000000000000000001500000000000000004000000000000000001600000000000000004000000000000000001700000000000000004000000000000000001800000000000000004000000000000000001900000000000000004000000000000000001A00000000000000004000000000000000001B00000000000000004000000000000000001C00000000000000004000000000000000001D00000000000000004000000000000000001E0000000000000000400000000000000000FF060000BE000000000102030405060708090A0B0C0D0E0F101112001E262E373F474F5764707D8995A6B6C7DBF0000000000000000000000000000000000000000202030304040405050606060808080909090904040506070809090A0A0B0C0E1011121212120406080A0B0D0E0F10111216171A1C1E1E1E1E04080A0C0E101112141516181B1D1F21222222040A0C0E1113151718191A1C1E232628282828040B0E111416181B1C1E20212326292C2C2C2C040C1013161A1C1E20222426282C3030303030000F0000040000006F7499E800000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000FC9D6F",
    "2E7201523030323241524DA80200007F04000040000000000000000000000040000000000000000000000000000040000000000000000000000000000040000000000000000000000000000040000000000000000000007F1200000400000000000000FF120000020000000000FF13000070000000000000000000000040000000000000000000000000000040000000000000000000000000000040000000000000000000000000000040000000000000000000000000000040000000000000000000000000000040000000000000000000000000000040000000000000000000000000007F2200000400000000000000FF220000020000000000FF23000070000000000000000000000040000000000000000000000000000040000000000000000000000000000040000000000000000000000000000040000000000000000000000000000040000000000000000000000000000040000000000000000000000000000040000000000000000000000000007F3200000400000000000000FF320000020000000000FF33000070000000000000000000000040000000000000000000000000000040000000000000000000000000000040000000000000000000000000000040000000000000000000000000000040000000000000000000000000000040000000000000000000000000000040000000000000000000000000007F4200000400000000000000FF420000020000000000FF43000070000000000000000000000040000000000000000000000000000040000000000000000000000000000040000000000000000000000000000040000000000000000000000000000040000000000000000000000000000040000000000000000000000000000040000000000000000000000000007F75000006000000000000000000FF750000020000000000000F000004000000D7C8DBF00000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000037E1EDEA",
    };
   int hexArrayLen;

   std::string FileName;
   /*char* FileName[] =
   {    "Dataset1.txt",
        "Dataset2.txt",
        "Dataset3.txt",
        "Dataset4.txt",
    };*/
    int num_of_elements = sizeof(hexArray) / sizeof(hexArray[0]);
    for(int i = 0; i < num_of_elements ; i++)
    {
        hexArrayLen = strlen(hexArray[i]); /* Subtract 1 to exclude the null terminator*/
        char *hexArraySpace = (char*)(malloc(4*hexArrayLen));/* Allocate memory for binary array*/
        memset(hexArraySpace,0x00,4*hexArrayLen);
        (void)InsertSpacesWithBackslash(hexArraySpace,hexArray[i]);
        cout << hexArraySpace << endl;
        FileName.clear();
        FileName.append("Dataset_ToBeUsedWithCppArray_");
        char cmd[32];
        memset(cmd,0,sizeof(cmd));
        sprintf(cmd,"%02d",i);
        FileName += cmd;
        FileName += ".txt";
        ofstream DatasetFile(FileName);

        /* Write to the file*/
        /*DatasetFile << hexArraySpace << endl;*/
        DatasetFile << "echo " << hexArraySpace << " | isotpsend -s 773 -d 7dd -p55 can0" << endl;

        /* Close the file*/
        DatasetFile.close();

        free(hexArraySpace);
    }


    for(int i = 0; i < num_of_elements ; i++)
    {
        hexArrayLen = strlen(hexArray[i]); /* Subtract 1 to exclude the null terminator*/
        char *hexArraySpace = (char*)(malloc(4*hexArrayLen));/* Allocate memory for binary array*/
        memset(hexArraySpace,0x00,4*hexArrayLen);
        (void)InsertSpacesNoBackslash(hexArraySpace,hexArray[i]);
        cout << hexArraySpace << endl;
        FileName.clear();
        FileName.append("Dataset_ToBeUsedWithZUODIS_");
        char cmd[32];
        memset(cmd,0,sizeof(cmd));
        sprintf(cmd,"%02d",i);
        FileName += cmd;
        FileName += ".txt";
        ofstream DatasetFile(FileName);

        /* Write to the file*/
        DatasetFile << "echo " << hexArraySpace << " | isotpsend -s 773 -d 7dd -p55 can0" << endl;

        /* Close the file*/
        DatasetFile.close();

        free(hexArraySpace);
    }

    return 0;
}
