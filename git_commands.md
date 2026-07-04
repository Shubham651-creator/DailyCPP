# git push origin <branch_name>
[upload commited files into github]

# git pull origin <brand_name>
[take files from github into our local system]

# git status
[show status of stages and unstaged files]

# git commit -m "messge" 
[write commit to the staged file]

# git reset --hard 0102ffeb60be523ae074ac27144b449cc9d913cc(commit id)
[change HEAD position to that "commit id" ]

# git branch 
# git checkout -b <new_branch_name>
[to create a new branch]

# git commit --amend
[to change current commit ]

# git rebase -i HEAD~4 (commit number)
[to changes the multiple commits ]
    - Pick 
    - Squesh (combine multiple commit in one)
    - revert (edit)

# git cherry pick
[git commit to be picked by reference and appended to current working HEAD]
[move commit from one branch into another branch ]

# git stash -u
[takes your uncommited changes and save them away for later use, and then reverts them from your working copy]

# git stash apply
[reverts your uncommited changes]