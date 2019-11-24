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

Σε αυτό το ερώτημα θα παρουσιάσουμε κάποια στοιχεία για τα in-order CPU models που περιέχει ο gem5.

1.AtomicSimpleCpu:

Το μοντέλο AtomicSimpleCpu χρησιμοποιεί Atomic memory accesses.Το συγκεκριμένο μοντέλο εκτελεί όλες διεργασίες μίας εντολής σε ένα κύκλο του ρολογιού.

2.TimingSimpleCpu:

Το μοντέλο TimingSimpleCpu χρησιμοποιεί Timing memory accesses το οποίο σημαίνει ότι περιμένει μέχρι να ολοκληρωθεί η πρόσβαση στην μνήμη και μετά συνεχίζει ενώ οι caches αγνοούνται.Το συγκεκριμένο μοντέλο δεν περιέχει pipelining δήλαδη επεξεργάζεται μία εντολή την φορά.Κάθε αριθμητική εντολή εκτελείται σε ένα κύκλο ενώ η πρόσβαση στην μνήμη απαιτεί παραπάνω κύκλους.

3.MinorCPU:

Αρχικά,το μοντέλο MinorCPU θεωρείται πιο ρεαλιστικό και πιο λεπτομερές σε σχέση με τα προηγούμενα μοντέλα που παρουσιάσαμε.Επίσης,να προσθέσουμε ότι το συγκεκριμένο μοντέλο αρχικά δημιουργήθηκε για να υποστηρίζει ARM ISA αλλά φυσικά είναι εφαρμόσιμο και σε άλλες ISAs.Το MinorCPU μοντέλο έχει τέσσερα στάδια in-order execution pipeline,ρυθμιζόμενες δομές δεδομένων ροής εκτέλεσης οπότε μπορεί να προσαρμοστεί σε κάποιον συγκεκριμένο επεξεργαστή.Τα τέσσερα στάδια του pipeline είναι τα:

1.Fetch1

2.Fetch2

3.Decode

4.Execute

Επίσης,χρησιμοποιεί walk caches,L1 instruction cache,L1 data cache και L2 cache.

4.High-Performance In-orderCPU(HPI)

Η υλοποίηση του συγκεκριμένου μοντέλου έχει βασιστεί σε μεγάλο βαθμό στο MinorCPU model.Παρακάτω θα παρουσιάσουμε τα στοιχεία αυτού του μοντέλου.

1.Pipeline του επεξεργαστή

Έχει τα ίδια τέσσερα στάδια pipeline με το MinorCPU model τα οποία έχουμε παρουσιάσει παραπάνω.

2.Ελεγκτής διακοπών(Interrupt Controller)

Διαχειρίζεται τυχών διακοπές που μπορεί να προκύψουν και ορίζει και διακοπές όπου έιναι δόκιμο.

3.Floating-Point μονάδα(Floating Point Unit-FPU) και Μονάδα Επεξεργασίας Δεδομένων(Data Processing Unit-DPU)

H DPU περιέχει γενικού σκοπού καταχωρητές και καταχωρητές του συστήματος. Μέσω αυτής μπορεί να γίνει διαμόρφωση και έλεγχος του συστήματος μνήμης και αποκωδικοποιεί και εκτελεί εντολές. Η FPU περιέχει αρχείο με τους floating-point καταχωρητές και τους καταχωρητές κατάστασης.

4.L1 caches

Το μοντέλο διαθέτει μια L1 instruction cache και μία L1 data cache.

5.Μονάδα Διαχείρισης Μνήμης(Memory Management Unit)

Μία σημαντική λειτουργία αυτής της μονάδας είναι ότι επιτρέπει στο σύστημα να τρέχει πολλαπλές διεργασίες ως ανεξάρτητα προγράμματα τα οποία τρέχουν στην δικία τους ψηφιακή θέση μνήμης.

6.Level 2 σύστημα μνήμης(Level 2 memory system)

Αποτελείται από το Snoop Control Unit (SCU),Coherence Bus Interface και την L2 cache.

#### Ερώτημα 3a


