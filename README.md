VoxBox make file and install profile
------------------------------------

The easiest way to deploy. 

If you don't have them yet you will need `drush` and `drush make`:-
Install drush: http://drupalcode.org/project/drush.git/blob/HEAD:/README.txt
Then install drush make by typing: `drush dl drush_make`

Create a file make file `voxbox.make` containing:-

    core = 6.x
    api = 2
    projects[] = drupal
    projects[voxbox][type] = "profile"
    projects[voxbox][download][type] = "git"
    projects[voxbox][download][url] = "git://github.com/ekes/voxbox.git"

Then run it: `drush make voxbox.make docroot` Where docroot is the path/to/the/directory where you want the public document root of the website.

You should have now got all the code. You can either point your browser at the site the website and install using the UI; or you can `cd docroot; drush site-install --db-url=mysql://user:password@host/database voxbox` and get the full default instal.
