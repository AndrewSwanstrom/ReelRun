# ReelRun
 
When touching the project, it is VERY important that large files such as textures, models, and other art assets ONLY go in the Art folder; this is the only folder set up for Git LFS, and therefore is the only one that can actually handle large files.

When committing to the project, you first want to create a branch off of develop for whatever feature you are working on. For example, if I'm working on the lighting for the Western Level, I will split off a branch from the develop branch (the branch with everything on it), title it "Western Level Lighting," and then work on my lighting on this branch. After you create a branch, you can work on that branch for however long you need to, but try to have the feature done as soon as possible (within a week or two), that way your branch doesn't get so out of date that it begins to cause merge conflicts. You can commit as many times as you need to on this branch, you're the only one using it. After you're done with the feature you're working on, you're going to merge the branch into develop through a pull request. If you've never done this before, I (Andrew) can show you how, just ping me on Discord and I can jump in a call. It should be a button on Github Desktop. If there are merge conflicts that you don't know how to solve, just ping me and I can help you.

Essentially, the Github workflow is: create a feature branch, work on the feature on this branch, commit the final feature changes to the branch, merge the branch back into develop, delete the branch, and repeat. NEVER commit straight to develop, only merge branches into develop once a feature is fully working.

And to clarify, a "feature" can be anything from a full and complete level, to a combat system, to a singular bush asset.

For the artists in particular, if you don't want to use Github for whatever reason, feel free to ping me (Andrew) on Discord and I can add your assets into the project.

JUST AS A REMINDER, DO NOT COMMIT TO DEVELOP. YOU KNOW WHO YOU ARE (ZONG).