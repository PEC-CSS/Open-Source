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

- Reset your local branch to Remote branch
```
git fetch origin
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
