- Create a new branch: Branching
``` 
git checkout -b name_of_branch 
```

- add changed file: Staging
``` 
git add .  OR git add file_name 
```

- Commit changes with message: Commiting
``` 
git commit -m "a_relevant_message"
```

- Pushing your changes to the forked repo: Pushing
``` 
git push origin name_of_branch
```

- Pulling changes from forked repo: Pulling
``` 
git pull origin name_of_branch
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
git stash
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
