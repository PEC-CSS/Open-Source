- To configure user name to git
``` 
git config --global user.name <your_user_name>
```

- To configure user emailId to git
``` 
git config --global user.email <email_id>
```

- To List the config of git
``` 
git config -l 
```

- Create a new branch: Branching
``` 
git checkout -b name_of_branch 
```

- Checkout existing remote branch: Branching
``` 
git checkout <branch_name> 
```

- add changed file: Staging
``` 
git add .  OR git add file_name 
```

- add all unstaged files: Staging
``` 
git add -A 
```

- Commit changes with message: Commiting
``` 
git commit -m "a_relevant_message"
```

- Pushing your changes to the forked repo: Pushing
``` 
git push origin name_of_branch
```

- Force pushing changes to the forked repo: Pushing
``` 
git push origin <name_of_branch> -f
```

- Pulling changes from forked repo: Pulling
``` 
git pull origin name_of_branch
```

- To check the current branch 
``` 
git branch
```

- Move to different branch
``` 
git checkout main //if you are on a different branch
git checkout name_of_branch
```

- Check current status of changes
```
git status
```

- Check logs (commit history and related details)
```
git log
```

- Check logs and display them as a graph
```
git log --graph --oneline --decorate --all
```

- set up remote upstream and fetch
```
git remote add upstream https://github.com/PEC-CSS/Open-Source.git
git fetch upstream
```

- Reset your local branch to Remote branch
```
git fetch upstream //OR git fetch origin - if you are working on the original repo
git reset --hard origin/name_of_branch
git clean -f
```

- Change name of current branch
```
git branch -m <new_name> 
```

- change last commit's message
``` 
git commit --amend -m "New commit message."
```

- Move unstaged changes to stash
```
git stash OR git stash save <unique_name>
```

- Move unstaged and untracked changes/files to stash
```
git stash -u
```

- Merge last added changes from stash with current branch
```
git stash pop
```

- List all stashed changes
```
git stash list
```

- To revert unstaged changes in Git
```
git checkout <filename>
```

- To revert staged changes in Git
```
git reset filename
```

- Steps to rebase from source branch to destination branch
```
Should be in destination branch
git pull --rebase origin <source_branch>
If any conflicts, then resolve the conflicts and git add the resolved files.
git rebase --continue
If no conflicts, it will be successfully rebased.
git push origin <destination_branch> -f
```

- To include the specific commit to another branch (cherry-pick) with committing directly
```
git cherry-pick <commit_id>
```

- To include the specific commit to another branch (cherry-pick) without committing directly
```
git cherry-pick <commit_id> --no-commit
```

- To include the specific range of commits to another branch (cherry-pick) 
```
git cherry-pick <commit_id_1>..<commit_id_2>
```

- Show changes between commits, commit and working tree 
```
git diff
```
