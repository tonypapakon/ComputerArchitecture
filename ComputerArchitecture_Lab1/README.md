<p align="center"><img src="https://arch.cs.ucdavis.edu/assets/images/gem5-logo.png" alt="Gem5-logo" width="250"/></p>

# Εργασία Πρώτου Εργαστηρίου Αρχιτεκτονικής Υπολογιστών

**Παπακωνσταντίνου Αντώνης, ΑΕΜ 8977**

**Κασιούλης Φίλιππος, ΑΕΜ 8966**

## Ερωτήματα Πρώτου Μέρους

Χρησιμοποιήσαμε την εντολή που μας δόθηκε για την μελέτη του συστήματος που θα εξομοιώσουμε. Η εντολή εκτελεί ένα precompiled πρόγραμμα hello με τις παραμέτρους για το σύστημα που ορίζει το αρχείο starter_se.py σε Minor model CPU.

```$ ./build/ARM/gem5.opt configs/example/arm/starter_se.py --cpu="minor" "tests/test-progs/hello/bin/arm/linux/hello"```

### Ερώτημα 1.

Καταγραφή βασικών χαρακτηριστικών στυστήματος από το starter_se.py για την εξομοίωση του Gem5:

**a.CPU**:Minor model CPU απ΄την προσωπική μας επιλογή στην εντολή που δηλώσαμε πιο πάνω (--cpu="minor").

**b.Συχνότητα Λειτουργίας/Αριθμός Πυρήνων**:Η συχνότητα λειτουργίας είναι η default τιμή η οποία είναι στα 4GHz. Επίσης και ο αριθμός πυρήνων είναι η default τιμή η οποία είναι ένας πυρήνας.

**c.Caches**:64 bytes. Οι caches εξαρτώνται από τον τύπο CPU που δίνουμε ως παράμετρο, οπότε αφου χρησιμοποιούμε minorCPU έχουμε L1 και L2 cache σύμφωνα με την δήλωση των τύπων CPU στην αρχή του αρχείου.

**d.Μνήμη**: Το μέγεθος της φυσικής μνήμης είναι η default τιμή η οποία είναι 2GB, το είδος της κύριας μνήμης είναι πάλι το default και είναι DDR3_1600_8x8 (συχνότητα λειτουργίας: 1600MHz, 2 channels).

### Ερώτημα 2.

Στο ερώτημα αυτό θα επαληθεύσουμε τα αποτελέσματα του πρώτου ερωτήματος κάνοντας μελέτη των αρχείων config.ini και config.json και θα παραθέσουμε τα αντίστοιχα πεδία.

**a.CPU**: Minor model CPU

**config.ini**:

```type=MinorCPU```

**config.json**:

```"type": "MinorCPU"```

**b.Συχνότητα Λειτουργίας**: 4GHz(το clock μετράει σε ns)

**config.ini**:

```clock=250```

**config.json**:

```"clock": [250]```

**c.Caches**: 64 bytes

**config.ini**:

```cache_line_size=64```

**config.json**:

```"cache_line_size": 64```

**d.Μνήμη**: 2GB (2^31, 2 channels)

**config.ini**:

```mem_ranges=0:2147483647```
```memories=system.mem_ctrls0 system.mem_ctrls1```

**config.json**:

``` "mem_ranges": ["0:2147483647"]```

### Ερώτημα 3.

Μετά από αναζήτηση στο site του Gem5 (gem5.org) θα παρουσιάσουμε κάποια στοιχεία για in-order CPUs στο gem5. Παρατηρήσαμε ότι υπάρχουν τρία μοντέλα in-order CPUs: το MinorCPU, το TimingSimpleCPU και το AtomicSimpleCPU, με τα τελευταία δυο να βασίζονται στο SimpleCPU. 

**1.MinorCPU**: 

Το μοντέλο MinorCPU αποτελεί το πιο ρεαλιστικό απ όλα τα αναγραφόμενα μοντέλα επίσης είναι και το πιο λεπτομερές απ όλα. Η δομή του pipeline του ακολουθεί τέσσερα στάδια `Fetch1 Fetch2 Decode Execute`, αλλά έχει ρυθμιζόμενες δομές δεδομένων ροής εκτέλεσης οπότε μπορεί να προσαρμοστεί σε κάποιον συγκεκριμένο επεξεργαστή. Το σταθερό pipeline του βοηθάει στην αναγνώριση και οπτικοποίηση μέσα σε αυτό της κάθε εντολής από μία προσομοίωση.

**2.TimingSimpleCPU**:

Το TimingSimpleCPU αποτελεί υλοποίηση του SimpleCPU μοντέλου που χρησιμοποιεί πρόσβαση στη μνήμη τύπου timing (_timing memory access_). Αυτό σημαίνει ότι σε κάθε πρόσβαση στην cache καθυστερεί και περιμένει την απάντηση από το σύστημα μνήμης πριν συνεχίσει την εκτέλεση εντολών, υπάρχει δηλαδή resource contention και queuing delay, αφού ο επεξεργαστής περιμένει την ολοκλήρωση της πρόσβασης στην μνήμη για να συνεχίσει.

**3.AtomicSimpleCPU**:

Το AtomicSimpleCPU αποτελεί και αυτό υλοποίηση του SimpleCPU μοντέλου που χρησιμοποιεί πρόσβαση στη μνήμη τύπου atomic (_atomic memory access_). Αυτό σημαίνει ότι υπολογίζει προσεγγιστικά τον χρόνο πρόσβασης στην cache από τις χρονικές προσεγγίσεις των atomic accesses οι οποίες επιστρέφουν μια προσέγγιση του χρόνου που θα χρειαστούν για το access, ενώ η επιστροφή τιμής γίνεται στο τέλος του access function. Με αυτό τον τρόπο αποφεύγεται το queuing delay και το resource contention διότι η cpu γνωρίζει προσεγγιστικά τον χρόνο πρόσβασης στην μνήμη πριν αυτή ολοκληρωθεί.

#### Ερώτημα 3.a/b

Παραθέτουμε το πρόγραμμα που γράψαμε σε C (επίσης βρίσκεται και στο repository στο git μας):

```
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
srand(time(NULL));
int r=rand();
printf("My random number is %d:/",r);
  
return 0;
}
```

Κάνουμε Compile το πρόγραμμα με την εντολή:

```arm-linux-gnueabihf-gcc --static myprogram.c -o myprogram_arm ```

Εκτελέσαμε την εξομοίωση με την εντολή που μας δόθηκε σε MinorCPU model και τα ορίσματα που βρίσκονται στο `se.py`:

```$ ./build/ARM/gem5.opt -d random_minor configs/example/se.py --cpu-type=MinorCPU --caches -c lab1/myprogram_arm```

Μελετώντας το αρχείο stats.txt, παραθέτουμε τα αποτελέσματα για τους χρόνους εκτέλεσης σε MinorCPU:

```final_tick                                   43620000                       # Number of ticks from beginning of simulation (restored from checkpoints and never reset)```

```sim_seconds                                  0.000044                       # Number of seconds simulated```

Εκτελέσαμε ξανά την εξομοίωση σε TimingSimpleCPU model αυτή την φορά, με την εντολή:

```$ ./build/ARM/gem5.opt -d random_tim_simple configs/example/se.py --cpu-type=TimingSimpleCPU --caches -c lab1/myprogram_arm```

Μελετήσαμε ξανά το αρχείο stats.txt, παραθέτουμε τα αποτελέσματα για τους χρόνους εκτέλεσης σε TimingSimpleCPU:

```final_tick                                   58444000                       # Number of ticks from beginning of simulation (restored from checkpoints and never reset)```

```sim_seconds                                  0.000058                       # Number of seconds simulated```

Παρατηρούμε ότι η εξομοίωση με MinorCPU model τρέχει πιο γρήγορα στον εξομοιωτή απ αυτήν του TimingSimpleCPU, το οποίο είναι λογικό αποτέλεσμα καθώς το MinorCPU model χρησιμοποιεί pipeline στην εκτέλεση των εντολών.

#### Ερώτημα 3.c

Σ αυτό το ερώτημα χρησιμοποιήσαμε πάλι τα μοντέλα του MinorCPU, καθώς και του TimingSimpleCPU αλλάζοντας πρώτα την συχνότητα λειτουργίας του επεξεργαστή και μετά αλλάζοντας την τεχνολογία της μνήμης.

**Συχνότητα λειτουργίας: 4GHz**

**->** Για MinorCPU model εκτελέσαμε την εντολή:

```./build/ARM/gem5.opt -d random_minor_4hz configs/example/se.py --cpu-type=MinorCPU --cpu-clock=4GHz --caches -c lab1/myprogram_arm```

Μελετάμε το αρχείο stats.txt, για τυχών αλλαγές στους χρόνους εκτέλεσης και παραθέτουμε τα αποτελέσματα παρακάτω:

```final_tick                                   36378000                       # Number of ticks from beginning of simulation (restored from checkpoints and never reset)```

```sim_seconds                                  0.000036                       # Number of seconds simulated```

Παρατηρούμε βελτίωση στον χρόνο εκτέλεσης από 0.000044 σε 0.000036.

**->** Για TimingSimpleCPU model εκτελέσαμε την εντολή:

```./build/ARM/gem5.opt -d random_timsimple_4hz configs/example/se.py --cpu-type=TimingSimpleCPU --cpu-clock=4GHz --caches -c lab1/myprogram_arm```

Μελετάμε το αρχείο stats.txt, για τυχών αλλαγές στους χρόνους εκτέλεσης και παραθέτουμε τα αποτελέσματα παρακάτω:

```final_tick                                   42810500                       # Number of ticks from beginning of simulation (restored from checkpoints and never reset)```

```sim_seconds                                  0.000043                       # Number of seconds simulated```

Παρατηρούμε βελτίωση στον χρόνο εκτέλεσης από 0.000058 σε 0.000043.

**Τεχνολογία Μνήμης: DDR4_2400_16x4**

**->** Για MinorCPU model εκτελέσαμε την εντολή:

```./build/ARM/gem5.opt -d random_minor_ddr4 configs/example/se.py --cpu-type=MinorCPU --mem-type=DDR4_2400_16x4 --caches -c lab1/myprogram_arm```

Μελετάμε το αρχείο stats.txt, για τυχών αλλαγές στους χρόνους εκτέλεσης και παραθέτουμε τα αποτελέσματα παρακάτω:

```final_tick                                   42310000                       # Number of ticks from beginning of simulation (restored from checkpoints and never reset)```

```sim_seconds                                  0.000042                       # Number of seconds simulated```

Παρατηρούμε βελτίωση στον χρόνο εκτέλεσης από 0.000044 σε 0.000042.

**->** Για TimingSimpleCPU model εκτελέσαμε την εντολή:

```./build/ARM/gem5.opt -d random_timsimple_ddr4 configs/example/se.py --cpu-type=TimingSimpleCPU --mem-type=DDR4_2400_16x4 --caches -c lab1/myprogram_arm```

Μελετάμε το αρχείο stats.txt, για τυχών αλλαγές στους χρόνους εκτέλεσης και παραθέτουμε τα αποτελέσματα παρακάτω:

```final_tick                                   58301000                       # Number of ticks from beginning of simulation (restored from checkpoints and never reset)```

```sim_seconds                                  0.000058                       # Number of seconds simulated```

Δεν παρατηρούμε σ αυτήν την περίπτωση κάποια ιδιαίτερη βελτίωση στον χρόνο εκτέλεσης, από 0.000058 σε 0.000058.

**Lab feedback**
Σε γενίκες γραμμες το πρώτο εργαστήριο ήταν αρκέτο ενδιαφέρον και ήταν μια καλή εισαγωγή για το gem_5 .Ενά πολύ θετικό του στοιχείο ήταν η εκμάθηση του github και της Μarkdown γλώσσας καθώς είναι πολύ βοηθητικά εργαλεία για την μετέπειτα πορεία μας.Προσώπικα δυσκολευτήκαμε στην εγκατάσταση του gem_5 στον υπολογίστη μας καθώς δεν είχαμε linux base υπολόγιστη και επρέπε να γίνει σε Virtual Machine.
