# Εργασία Πρώτου Εργαστηρίου Αρχιτεκτονικής Υπολογιστών

**Παπακωνσταντίνου Αντώνης, ΑΕΜ 8977**

**Κασιούλης Φίλιππος, ΑΕΜ 8966**

## Ερωτήματα Πρώτου Μέρους

Χρησιμοποιήσαμε την εντολή που μας δόθηκε για την μελέτη του συστήματος που θα εξομοιώσουμε. Η εντολή εκτελεί ένα precompiled πρόγραμμα hello με τις παραμέτρους για το σύστημα που ορίζει το αρχείο starter_se.py σε Minor model CPU.

```$ ./build/ARM/gem5.opt configs/example/arm/starter_se.py --cpu="minor" "tests/test-progs/hello/bin/arm/linux/hello"```

### Ερώτημα 1

Καταγραφή βασικών χαρακτηριστικών στυστήματος από το starter_se.py για την εξομοίωση του Gem5:

**a.CPU**:Minor model CPU απ΄την προσωπική μας επιλογή στην εντολή που δηλώσαμε πιο πάνω (--cpu="minor").

**b.Συχνότητα Λειτουργίας/Αριθμός Πυρήνων**:Η συχνότητα λειτουργίας είναι η default τιμή η οποία είναι στα 4GHz. Επίσης και ο αριθμός πυρήνων είναι η default τιμή η οποία είναι ένας πυρήνας.

**c.Caches**:64 bytes. Οι caches εξαρτώνται από τον τύπο CPU που δίνουμε ως παράμετρο, οπότε αφου χρησιμοποιούμε minorCPU έχουμε L1 και L2 cache σύμφωνα με την δήλωση των τύπων CPU στην αρχή του αρχείου.

**d.Μνήμη**: Το μέγεθος της φυσικής μνήμης είναι η default τιμή η οποία είναι 2GB, το είδος της κύριας μνήμης είναι πάλι το default και είναι DDR3_1600_8x8 (συχνότητα λειτουργίας: 1600MHz, 2 channels).

### Ερώτημα 2

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

**d.Μνήμη**: 2GB

**config.ini**:

```mem_ranges=0:2147483647```

**config.json**:

``` "mem_ranges": ["0:2147483647"]```

### Ερώτημα 3

Μετά από αναζήτηση στο site του Gem5 (gem5.org) θα παρουσιάσουμε κάποια στοιχεία για in-order CPUs στο gem5. Παρατηρήσαμε ότι υπάρχουν τρία μοντέλα in-order CPUs: το MinorCPU, το TimingSimpleCPU και το AtomicSimpleCPU, με τα τελευταία δυο να βασίζονται στο SimpleCPU. 

**1.MinorCPU**: 

Το μοντέλο MinorCPU αποτελεί το πιο ρεαλιστικό απ όλα τα αναγραφόμενα μοντέλα επίσης είναι και το πιο λεπτομερές απ όλα. Η δομή του pipeline του ακολουθεί τέσσερα στάδια `Fetch1 Fetch2 Decode Execute`, αλλά έχει ρυθμιζόμενες δομές δεδομένων ροής εκτέλεσης οπότε μπορεί να προσαρμοστεί σε κάποιον συγκεκριμένο επεξεργαστή. Το σταθερό pipeline του βοηθάει στην αναγνώριση και οπτικοποίηση μέσα σε αυτό της κάθε εντολής από μία προσομοίωση.

**2.TimingSimpleCPU**:

**3.AtomicSimpleCPU**:


#### Ερώτημα 3a

Παραθέτουμε το πρόγραμμα που γράψαμε σε C (επίσης βρίσκεται και στο repository στο git μας):

```
#iclude <stdio.h>

int main(){
  return 0;
}
```

Εκτελέσαμε την εξομοίωση με την εντολή που μας δόθηκε σε MinorCPU model και τα ορίσματα που βρίσκονται στο `se.py`:

```$ ./build/ARM/gem5.opt configs/example/se.py --cpu-type=MinorCPU --caches tests/test-progs/hello/bin/arm/linux/myprog```

Μελετώντας το αρχείο stats.txt, παραθέτουμε τα αποτελέσματα για τους χρόνους εκτέλεσης σε MinorCPU:

```final_tick                                   3                       # Number of ticks from beginning of simulation (restored from checkpoints and never reset)```

```sim_seconds                                  0                       # Number of seconds simulated```

Εκτελέσαμε ξανά την εξομοίωση σε TimingSimpleCPU model αυτή την φορά, με την εντολή:

```$ ./build/ARM/gem5.opt configs/example/se.py --cpu-type=TimingSimpleCPU --caches tests/test-progs/hello/bin/arm/linux/myprog```

Μελετήσαμε ξανά το αρχείο stats.txt, παραθέτουμε τα αποτελέσματα για τους χρόνους εκτέλεσης σε TimingSimpleCPU:

```final_tick                                   3                       # Number of ticks from beginning of simulation (restored from checkpoints and never reset)```

```sim_seconds                                  0                       # Number of seconds simulated```

Παρατηρούμε ότι η εξομοίωση με MinorCPU model τρέχει πιο γρήγορα στον εξομοιωτή απ αυτήν του TimingSimpleCPU, το οποίο είναι λογικό αποτέλεσμα καθώς το MinorCPU model χρησιμοποιεί pipeline στην εκτέλεση των εντολών.
