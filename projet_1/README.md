# Projet 1 groupe 29 Caulier Camille Meluzola Noah
#lancement 
Pour compiler le code vous pouvez utiliser la commande
``make all``

pour lancer une executable il faut noter que tous les executables sont localisés dans le dossier ``executable``. Pour run un fichier spécifique il faut alors lancer comme suit
``./executable/nom_du_executable nombre_de_variables``

#performance
pour pouvoir tester la performance des programmes vous pouvez utiliser la commande
* ``make performance_all``

après cela les temps seront enregistrés dans le fichier CSV. Pour vous gagner du temps nous avons nos donnés fait auparavant
dans le dossier ``/data_complete`` pour vous gagner du temps.

__NOTE__: nous avons fait plusieurs simulations pour les problèmes qui utilisent deux variables c'est à dire
on run plusieurs fois avec une variable constante pour voir les effets. Pour mieux comprendre vous pouvez voir
les plots qui sont déjà là.

#Plot 
pour pouvoir lancer les plots il faut d'abord avoir python3 pour installer python3 vous pouvez utiliser
la commande
* ``sudo apt-get install phyton3``

il faut également avoir les librairies ``pip``,``pandas`` et
``matplotlib``. Pour avoir les librarires vous pouvez utiliser les commandes suivantes dans le console.
* ``sudo apt-get install python3-pip``
* ``sudo apt-get install python3-pandas``
* ``pip3 install matplotlib``

Lorsque tout cela est fait vous pouvez créer les plots avec 
* ``make plot_all``

__NOTE__: à l'heure actuel les fichier pythons font les plots sur les donnés trouvés
dans le fichier ``/data_complete`` pour vous gagner du temps et de pas run ``make performance_all``

# Content :

``Makefile`` fichier avec tous les commandes make

__/source__
    dossier avec tous les fichier sources:
* ``my_semaphore.c`` fichier avec implémentation semaphore tache 2.4
* `` philosopher_problem.c`` philospher problem
* ``philosopher_problem_mod.c``philosopher problem mais avec les verrous active et semaphores de tache de 2.4
* ``posix.c`` tache 2.5 mais adapté pour posix
* ``producer_consumer.c`` producer consumer problem
* ``producer_consumer_mod`` producer consumer problem mais avec les verrous active et semaphores de tache de 2.4
* ``test_set_lib.c`` test set librairie
* ``test_set_performance.c`` test de performance pour test set algo
* ``test_test_set_lib`` test test set librairie
* ``test_test_set_perforamnce``test de performance pour test test set algo
* ``writer_reader.c`` writer reader problem
* ``writer_reader_mod.c`` writer reader problem mais avec les verrous active et semaphores de tache de 2.4


__/shell__
    dossier avec tous les scripts bash pour la performance

__/python_files__
    dossier avec tous les fichers pour les plots des performances
__/executable__
    dossier avec tous les executables 
__/plot__
    dossier avec tous les plots

__/data_complete__
    dossier avec tous les resultats de performances pour gagner du temps

__/data__
    dossier pour sauvgarder les data des performances


