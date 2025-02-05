#include <bits/stdc++.h>
using namespace std;

struct Course
{
    string professor;
    string courseCode;
    string coursetype;
    string branch;
    int credits;
};

int main()
{

    // Define file names
    const int numFiles = 5;
    string fileNames[numFiles] = {"PROJECT.txt", "PROJECT2.txt", "PROJECT3.txt", "PROJECT4.txt", "PROJECT5.txt"};
    // Array to store ifstream objects
    ifstream fileStreams[numFiles];

    // Open each file and store ifstream objects in the array
    for (int b = 0; b < numFiles; ++b)
    {
        if (b == 0)
        {
            cout << "Time Table for semester 1 :" << endl
                 << endl;
        }
        if (b == 1)
        {
            cout << "Time Table for semester 2 :" << endl
                 << endl;
        }
        if (b == 2)
        {
            cout << "Time Table for semester 3 :" << endl
                 << endl;
        }
        if (b == 3)
        {
            cout << "Time Table for semester 4 :" << endl
                 << endl;
        }
        if (b == 4)
        {
            cout << "Time Table for semester 5 :" << endl
                 << endl;
        }
        fileStreams[b].open(fileNames[b]);
        if (!fileStreams[b])
        {
            cerr << "Failed to open file: " << fileNames[b] << endl;
            // Handle error, such as return or exit
            return 1;
        }
        vector<Course> courses; // Vector to store courses

        string professor, courseCode, branch, coursetype;
        int credits;
        while (fileStreams[b] >> professor >> courseCode >> coursetype >> credits >> branch)
        {
            Course course;
            course.professor = professor;
            course.courseCode = courseCode;
            course.coursetype = coursetype;
            course.credits = credits;
            course.branch = branch;
            courses.push_back(course);
        }

        string arr[4][5][5];
        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 5; j++)
            {
                for (int k = 0; k < 5; k++)
                {
                    arr[i][j][k] = "-";
                }
            }
        }
        int i = 0;
        queue<string> q;
        queue<int> c;
        for (const auto &course : courses)
        {
            if (course.branch == "common" || course.branch == "CS,EVD" || course.branch == "ICT,CS,EVD" || course.branch == "ICT,CS" || course.branch == "CS" || course.branch == "CS,MNC,EVD" || course.branch == "ICT,CS,MNC")
            {
                string x = course.courseCode;
                string z = course.professor;
                int y = course.credits;
                q.push(x);
                c.push(y);
            }
        }
        int bb = 0;
        int aa = 0;
        int sq = 0;

        while (!q.empty())
        {
            string p = q.front();
            q.pop();
            int x = c.front();
            c.pop();
        label:
            if (arr[0][bb][aa] == "-")
            {
                for (int i = 0; i < x; i++)
                {
                label2:
                    if (arr[0][bb][aa] == "-")
                    {
                        arr[0][bb][aa] = p;
                        aa++;
                        if (aa == 5)
                        {
                            aa = 0;
                            if (sq > 0)
                                bb++;
                        }
                    }
                    else
                    {
                        aa++;
                        if (aa == 5)
                        {
                            aa = 0;
                            bb++;
                        }
                        goto label2;
                    }
                }
            }
            else
            {
                aa++;
                if (aa == 5)
                {
                    aa = 0;
                    bb++;
                }
                goto label;
            }
            bb++;
            if (bb == 5)
            {
                bb = 0;
                sq++;
                aa = 0;
            }
        }
        cout << "Time Table for ICT-CS : " << endl
             << endl;
        vector<string> timings = {"8 AM", "9 AM", "10 AM", "11 AM", "12 AM"};
        cout << "\tMON\tTUE\tWED\tTHU\tFRI\n";
        for (int i = 0; i < 5; i++)
        {
            cout << timings[i] << "\t";
            for (int j = 0; j < 5; j++)
            {
                cout << arr[0][i][j] << "\t";
            }
            cout << endl;
        }

        queue<string> q1;
        queue<int> c1;
        for (const auto &course : courses)
        {
            if (course.branch == "common" || course.branch == "MNC" || course.branch == "CS,MNC,EVD" || course.branch == "ICT,CS,MNC")
            {
                string x = course.courseCode;
                int y = course.credits;
                q1.push(x);
                c1.push(y);
            }
        }
        int ll = 0;
        int bh = 0;
        while (!q1.empty())
        {
            string p = q1.front();
            q1.pop();
            int x = c1.front();
            c1.pop();

        cc:
            if (arr[1][ll][bh] == "-")
            {
                for (int i = 0; i < x; i++)
                {
                    arr[1][ll][bh] = p;
                    bh++;
                ml:
                    if (arr[1][ll][bh] != "-")
                    {
                        bh++;
                        if (bh == 5)
                        {
                            bh = 0;
                            ll++;
                        }
                        goto ml;
                    }
                    if (bh == 5)
                    {
                        bh = 0;
                    }
                }
            }
            else
            {
                bh++;
                if (bh == 4)
                {
                    bh = 0;
                    ll++;
                }
                goto cc;
            }
            ll++;
            if (ll == 5)
            {
                ll = 0;
                bh = 0;
            }
        }
        cout << endl;
        cout << "Time Table for MNC : " << endl
             << endl;
        cout << "\tMON\tTUE\tWED\tTHU\tFRI\n";
        for (int i = 0; i < 5; i++)
        {
            cout << timings[i] << "\t";
            for (int j = 0; j < 5; j++)
            {
                if(arr[1][i][j].find("IE") != string::npos){
                    arr[1][i][j] = "-";
                }
                cout << arr[1][i][j] << "\t";
            }
            cout << endl;
        }

        queue<string> ok;
        queue<int> srr;
        for (const auto &course : courses)
        {
            if (course.branch == "common" || course.branch == "CS,EVD" || course.branch == "ICT,CS,EVD" || course.branch == "EVD" || course.branch == "CS,MNC,EVD")
            {
                string x = course.courseCode;
                int y = course.credits;
                // cout << x << endl;
                ok.push(x);
                srr.push(y);
            }
        }
        int m = 0;
        int n = 0;
        while (!ok.empty())
        {
            string p = ok.front();
            ok.pop();
            int x = srr.front();
            // cout << x << endl;
            srr.pop();

        ps:
            if (arr[2][m][n] == "-")
            {
                for (int i = 0; i < x; i++)
                {

                    arr[2][m][n] = p;
                    n++;

                lll:
                    if (arr[2][m][n] != "-")
                    {
                        n++;
                        if (n == 5)
                        {
                            n = 0;
                            m++;
                        }
                        goto lll;
                    }
                    if (n == 5)
                    {
                        n = 0;
                        // m++;
                    }
                }
            }
            else
            {
                n++;
                if (n == 4)
                {
                    n = 0;
                    m++;
                }
                goto ps;
            }
            m++;
            // cout << m << "   " << n << endl;
            if (m == 5)
            {
                m = 0;
                n = 0;
            }
        }

        cout << endl;
        cout << "Time Table for EVD : " << endl
             << endl;
        cout << "\tMON\tTUE\tWED\tTHU\tFRI\n";
        for (int i = 0; i < 5; i++)
        {
            cout << timings[i] << "\t";
            for (int j = 0; j < 5; j++)
            {
                cout << arr[2][i][j] << "\t";
            }
            cout << endl;
        }

        // Time table for sec-A-
        int r = 0;
        int row = 0;
        for (const auto &course : courses)
        {
            if (course.branch == "common" || course.branch == "ICT,CS,EVD" || course.branch == "ICT,CS" || course.branch == "ICT,CS,MNC")
            {
                string x = course.courseCode;
                int y = course.credits;
                if (r <= 2)
                    row = r + 2;
                else if (r == 3)
                    row = 0;
                else if (r == 4)
                    row = 1;
                int k = row;
                for (int j = 0; j < y; j++)
                {
                    if (k == 5)
                        k = 0;
                    arr[3][row][k] = x;
                    k++;
                }
                r++;
            }
        }
        queue<string> q2;
        queue<int> c2;
        for (const auto &course : courses)
        {
            if (course.branch == "ICT")
            {
                string x = course.courseCode;
                int y = course.credits;
                q2.push(x);
                c2.push(y);
                // cout << x << endl;
            }
        }
        int mm = 0;
        int nn = 0;
        while (!q2.empty())
        {
            string p = q2.front();
            q2.pop();
            int x = c2.front();
            // cout << x << endl;
            c2.pop();

        rab:

            if (arr[3][mm][nn] == "-")
            {
                int count = 0;
                for (int i = 0; i < x; i++)
                {
                    arr[3][mm][nn] = p;
                    nn++;
                    if (nn == 5)
                    {
                        nn = 0;
                        // mm++;
                    }
                    if (arr[3][mm][nn - 1] == arr[3][mm - 1][nn - 1] && arr[3][mm - 1][nn] != "-" && count < x)
                    {
                        nn++;
                    }

                pp:
                    // cout << mm << "     " << nn << endl;
                    if (arr[3][mm][nn] != "-")
                    {
                        // cout << nn << "pp" << endl;

                        nn++;
                        if (nn == 5)
                        {
                            nn = 0;
                            mm++;
                        }
                        goto pp;
                    }

                    if (nn == 5)
                    {
                        nn = 0;
                        mm++;
                    }
                    count++;
                }
            }
            else
            {
                nn++;
                if (nn == 5)
                {
                    nn = 0;
                    mm++;
                }
                goto rab;
            }
            mm++;

            if (mm == 5)
            {
                mm = 0;
                nn = 0;
            }
        }

        cout << endl;
        cout << "Time Table for ICT : " << endl
             << endl;
        for (int i = 0; i < 5; i++)
        {
            cout << timings[i] << "\t";
            for (int j = 0; j < 5; j++)
            {
                cout << arr[3][i][j] << "\t";
            }
            cout << endl;
        }
        cout << endl;
    }
    return 0;
}