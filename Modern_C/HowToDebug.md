# How to Debug the project :

1. Select only one Project(folder) at time.

2. Compile project using [-g](Breakpoint)
    > g++ -g *.cpp

    - which create a.out file

3. goto the "Run and Debug" Option

4. Click to "Show all config" option
    - choose cpp
    - which pop-up a "{} launch.json" file

5. In "{} launch.json" file,
    - goto 

    configuration:[
        - search for "cpp(gbd):launch"
    ]

    - after that, goto and paste path of output file(a.out) 
        >  "program": "/home/kpit/Desktop/coding/DailyCPP/Modern_C/Week3/1Sept23/a.out",

6. Now, goto "Run" 
    - start debugging(f5)

7. End
