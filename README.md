#Εργασία Πρώτου Εργαστηρίου Αρχιτεκτονικής Υπολογιστών

**Παπακωνσταντίνου Αντώνης ΑΕΜ 8977**

**Κασιούλης Φίλιππος ΑΕΜ**

Ερωτήματα Πρώτου Μέρους

Εφόσον ολοκληρώθηκε η εγκατάσταση του gem5 και προχωρήσαμε στην διαδικασία του build για ARM επεξεργαστή τρέξαμε τον gem5 σε SystemcallEmulation(SE)mode.Εκτελέσαμε το precompiled πρόγραμμα hello με τις παραμέτρους για το σύστημα που ορίζει το αρχείο starter_se.py για Minor model cpu.Η εντολή που χρησιμοποιήσαμε ήταν αυτή που μας δόθηκε:

    $ ./build/ARM/gem5.opt configs/example/arm/starter_se.py --cpu="minor" "tests/test-progs/hello/bin/arm/linux/hello" 

και συλλέξαμε τα ζητούμενα από έσας τα οποία παραθέτουμε παρακάτω.

Χρησιμοποιήσαμε την εντολή που μας δόθηκε για την μελέτη του συστήματος που θα εξομοιώσουμε. Η εντολή εκτελεί ένα precompiled πρόγραμμα hello με τις παραμέτρους για το σύστημα που ορίζει το αρχείο starter_se.py σε <<Minor model CPU>>.

>$ ./build/ARM/gem5.opt configs/example/arm/starter_se.py --cpu="minor" "tests/test-progs/hello/bin/arm/linux/hello"

###Ερώτημα 1

Καταγραφή βασικών χαρακτηριστικών στυστήματος από το starter_se.py για την εξομοίωση του Gem5:

**a.CPU**:Minor CPU απ΄την προσωπική μας επιλογή στην εντολή που δηλώσαμε πιο πάνω (--cpu="minor").
**b.Συχνότητα Λειτουργίας**:Είναι η default τιμή η οποία είναι στα 4GHz.
**c.Αριθμός Πυρήνων**:Είναι η default τιμή η οποία είναι ένας πυρήνας.
**d.Caches**:64 bytes. Οι caches εξαρτώνται από τον τύπο CPU που δίνουμε ως παράμετρο, οπότε αφου χρησιμοποιούμε minorCPU έχουμε L1 και L2 cache σύμφωνα με την δήλωση των τύπων CPU στην αρχή του αρχείου.
**e.Μνήμη**: Το μέγεθος της φυσικής μνήμης είναι η default τιμή η οποία είναι 2GB, το είδος της κύριας μνήμης είναι πάλι το default και είναι DDR3_1600_8x8 (συχνότητα λειτουργίας: 1600MHz, 2 channels).

Ερώτημα 2

Σε αυτό το ερώτημα μας ζητήθηκε τα επαληθεύσουμε τα στοιχεία που παρουσιάσαμε στο ερώτημα 1 κάνοντας μελέτη των αρχείων config.ini και config.json και να παραθέσουμε τα αντίστοιχα πεδία.Στην διαδικασία της παράθεσης πρώτα παραθέτουμε το όνομα του SimObject όπως έχει οριστεί στο starter_se.py,στο config.ini είναι το πεδίο μέσα στα brackets [] (e.g [system.cpu_cluster.cpus]) και στο config.json μέσα στα quotation marks(e.g "cpus") και μέτα την γραμμή που ορίζεται η πληροφορία που μας ενδιαφέρει:

1.CPU:Στην εξομοίωση χρησιμοποίειται Minor model CPU.

config.ini:

    [system.cpu_cluster.cpus]

    type=MinorCPU

config.json:

    "cpus":

    "type": "MinorCPU",

2.Συχνότητα λειτουργίας:Έχει οριστεί στα 4GHz.

config.ini:

    [system.cpu_cluster.clk_domain]

    clock=250

config.json:

    "clk_domain": {

    "name": "clk_domain",

    "clock": [

    250

3.Caches:Βλέπουμε στα αρχεία ότι δημιουργείτε μία L1 data cache.

config.ini:

    [system.cpu_cluster.cpus.dcache]

    type=Cache

config.json:

    "dcache": {

Μία L1 instruction cache.

config.ini:

    [system.cpu_cluster.cpus.icache]

    type=Cache

config.json:

    "icache": {

Μία L2 cache.

config.ini:

    [system.cpu_cluster.l2]

    type=Cache

config.json:

    "l2": {

Mία instruction to bus(itb) walker cache.

config.ini:

    [system.cpu_cluster.cpus.itb_walker_cache]

    type=Cache

config.json:

    "itb_walker_cache": {

Mία data to bus(dtb) walker cache.

config.ini:

    [system.cpu_cluster.cpus.dtb_walker_cache]

    type=Cache

config.json:

    "dtb_walker_cache": {

Επίσης,για αυτές τις caches μπορούμε να εντοπίσουμε και πολλά άλλα χαρακτηριστικά τους στα αρχεία config.ini και config.json όπως για παράδειγμα το μέγεθος τους.

L1 data cache-32KB:

config.ini:

    [system.cpu_cluster.cpus.dcache]

    size=32768

config.json:

    "system": "system",

    "sequential_access": false,

    "assoc": 2,

    "power_model": [],

    "cxx_class": "BaseSetAssoc",

    "p_state_clk_gate_max": 1000000000000,

    "path": "system.cpu_cluster.cpus.dcache.tags",

    "entry_size": 64,

    "block_size": 64,

    "type": "BaseSetAssoc",

    "size": 32768

L1 instruction cache-49KB.

config.ini:

    [system.cpu_cluster.cpus.icache]

    size=49152

config.json:

    "system": "system",

    "sequential_access": false,

    "assoc": 3,

    "power_model": [],

    "cxx_class": "BaseSetAssoc",

    "p_state_clk_gate_max": 1000000000000,

    "path": "system.cpu_cluster.cpus.icache.tags",

    "entry_size": 64,

    "block_size": 64,

    "type": "BaseSetAssoc",

    "size": 49152

L2 cache-1048KB.

config.ini:

    [system.cpu_cluster.l2]

    size=1048576

config.json:

    "system": "system",

    "sequential_access": false,

    "assoc": 16,

    "power_model": [],

    "cxx_class": "BaseSetAssoc",

    "p_state_clk_gate_max": 1000000000000,

    "path": "system.cpu_cluster.l2.tags",

    "entry_size": 64,

    "block_size": 64,

    "type": "BaseSetAssoc",

    "size": 1048576

Data to bus(dtb) walker cache-1KB.

config.ini:

    [system.cpu_cluster.cpus.dtb_walker_cache]

    size=1024

config.json:

    "system": "system",

    "sequential_access": false,

    "assoc": 8,

    "power_model": [],

    "cxx_class": "BaseSetAssoc",

    "p_state_clk_gate_max": 1000000000000,

    "path": "system.cpu_cluster.cpus.dtb_walker_cache.tags",

    "entry_size": 64,

    "block_size": 64,

    "type": "BaseSetAssoc",

    "size": 1024

Instruction to bus(itb) walker cache-1KB.

config.ini:

    [system.cpu_cluster.cpus.itb_walker_cache]

    size=1024

config.json:

    "system": "system",

    "sequential_access": false,

    "assoc": 8,

    "power_model": [],

    "cxx_class": "BaseSetAssoc",

    "p_state_clk_gate_max": 1000000000000,

    "path": "system.cpu_cluster.cpus.itb_walker_cache.tags",

    "entry_size": 64,

    "block_size": 64,

    "type": "BaseSetAssoc",

    "size": 1024

Το μήκος της γραμμής των caches είναι 64 bytes.

config.ini:

    [system]

    cache_line_size=64

config.json:

    "cache_line_size": 64,

4.Μνήμη Η μνήμη είναι ορισμένη στα 2GB.

config.ini:

    [system]

    mem_ranges=0:2147483647

config.json:

    "mem_ranges": [

    "0:2147483647"

Για την SDRAM τα χαρακτηριστικα της ορίζονται στα εξής πεδία.

config.ini:

    [system]

    memories=system.mem_ctrls0 system.mem_ctrls1

    [system.mem_ctrls0]

    [system.mem_ctrls1]

config.json:

    1."memories": [

    "system.mem_ctrls0",

    "system.mem_ctrls1"

    2."p_state_clk_gate_min": 1000,

    "ranks_per_channel": 2,

    "qos_q_policy": "fifo",

    "tRAS": 35000,

    "static_frontend_latency": 10000,

    "devices_per_rank": 8,

    "range": "0:2147483647:0:1048704",

    "mem_sched_policy": "frfcfs",

    "IDD2P12": 0.0,

    "device_rowbuffer_size": 1024,

    "activation_limit": 4,

    "tWTR": 7500,

    "enable_dram_powerdown": false,

    "qos_syncro_scheduler": false,

    "path": "system.mem_ctrls0",

    "bank_groups_per_rank": 0,

    "IDD2N": 0.032,

    "qos_turnaround_policy": null,

    "in_addr_map": true,

    "tRTW": 2500,

    "burst_length": 8,

    "tRTP": 7500,

    "eventq_index": 0,

    "IDD2P02": 0.0,

    "default_p_state": "UNDEFINED",

    "addr_mapping": "RoRaBaCoCh",

    "type": "DRAMCtrl",

    "IDD3P02": 0.0,

    "conf_table_reported": true,

    "tXS": 270000,

    "tXP": 6000,

    "IDD3N": 0.038,

    "tCCD_L_WR": 0,

    "kvm_map": true,

    "tXAW": 30000,

    "IDD3P12": 0.0,

    "IDD3N2": 0.0,

    "device_bus_width": 8,

    "cxx_class": "DRAMCtrl",

    "null": false,

    "tRRD_L": 0,

    "tRRD": 6000,

    "clk_domain": "system.clk_domain",

    "IDD6": 0.02,

    "IDD5": 0.23500000000000001,

    "tRCD": 13750,

    "IDD0": 0.055,

    "min_writes_per_switch": 16,

    "IDD02": 0.0,

    "page_policy": "open_adaptive",

    "read_buffer_size": 32,

    "IDD4R2": 0.0,

    "tXSDLL": 0,

    "p_state_clk_gate_bins": 20,

    "tRP": 13750

    3"p_state_clk_gate_min": 1000,

    "ranks_per_channel": 2,

    "qos_q_policy": "fifo",

    "tRAS": 35000,

    "static_frontend_latency": 10000,

    "devices_per_rank": 8,

    "range": "0:2147483647:1:1048704",

    "mem_sched_policy": "frfcfs",

    "IDD2P12": 0.0,

    "device_rowbuffer_size": 1024,

    "activation_limit": 4,

    "tWTR": 7500,

    "enable_dram_powerdown": false,

    "qos_syncro_scheduler": false,

    "path": "system.mem_ctrls1",

    "bank_groups_per_rank": 0,

    "IDD2N": 0.032,

    "qos_turnaround_policy": null,

    "in_addr_map": true,

    "tRTW": 2500,

    "burst_length": 8,

    "tRTP": 7500,

    "eventq_index": 0,

    "IDD2P02": 0.0,

    "default_p_state": "UNDEFINED",

    "addr_mapping": "RoRaBaCoCh",

    "type": "DRAMCtrl",

    "IDD3P02": 0.0,

    "conf_table_reported": true,

    "tXS": 270000,

    "tXP": 6000,

    "IDD3N": 0.038,

    "tCCD_L_WR": 0,

    "kvm_map": true,

    "tXAW": 30000,

    "IDD3P12": 0.0,

    "IDD3N2": 0.0,

    "device_bus_width": 8,

    "cxx_class": "DRAMCtrl",

    "null": false,

    "tRRD_L": 0,

    "tRRD": 6000,

    "clk_domain": "system.clk_domain",

    "IDD6": 0.02,

    "IDD5": 0.23500000000000001,

    "tRCD": 13750,

    "IDD0": 0.055,

    "min_writes_per_switch": 16,

    "IDD02": 0.0,

    "page_policy": "open_adaptive",

    "read_buffer_size": 32,

    "IDD4R2": 0.0,

    "tXSDLL": 0,

    "p_state_clk_gate_bins": 20,

    "tRP": 13750

Ερώτημα 3
Ερώτημα 3a

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
Ερώτημα 3b

Σε αυτό το ερώτημα τρέξαμε στο gem5 μία εξομοίωση με ορίσματα αυτά που δίνονται στο αρχείο se.py και εκτελέσαμε το πρόγραμμα prog_arm(τον πηγαίο κώδικα θα τον βρείτε στο repository μας στο github με το όνομα prog.c).Την παραπάνω εξομοίωση της τρέξαμε δύο φορές,την μία δίνοντας ως όρισμα από την γραμμή εντολών να χρησιμοποιηθεί MinorCPU model και την άλλη TimingSimpleCPU model.

Για να εκτελεστεί η εξομοίωση με MinorCPU model δώσαμε την εντολή:

    ./build/ARM/gem5.opt configs/example/se.py --cpu-type=MinorCPU --caches -c /home/uglynick/my_gem5/prog_arm

Και μελετώντας το αρχείο stats.txt(θα το βρείτε στο repository μας στο github με το όνομα stats_minor_cpu_model.txt) εντοπίσαμε τα εξής αποτελέσματα ως αναφορά τους χρόνους εκτέλεσης:

    final_tick 39328000 # Number of ticks from beginning of simulation (restored from checkpoints and never reset)

    sim_seconds 0.000039 # Number of seconds simulated

    sim_ticks 39328000 # Number of ticks simulated

Για να εκτελεστεί η εξομοίωση με TimingSimpleCPU model δώσαμε την εντολή:

    ./build/ARM/gem5.opt configs/example/se.py --cpu-type=TimingSimpleCPU --caches -c /home/uglynick/my_gem5/prog_arm

Και μελετώντας το αρχείο stats.txt(θα το βρείτε στο repository μας στο github με το όνομα stats_timing_simple_cpu_model.txt) εντοπίσαμε τα εξής αποτελέσματα ως αναφορά τους χρόνους εκτέλεσης:

    final_tick 49082000 # Number of ticks from beginning of simulation (restored from checkpoints and never reset)

    sim_seconds 0.000049 # Number of seconds simulated

    sim_ticks 49082000 # Number of ticks simulated

Βλέπουμε ότι η εξομοίωση με MinorCPU model είναι ταχύτερη από αυτήν με TimingSimpleCPU model το οποίο είναι αναμενόμενο λόγω του ότι το MinorCPU model χρησιμοποιεί pipeline στην εκτέλεση των εντολών αλλά και caches.
Ερώτημα 3c

Σε αυτό το ερώτημα τρέξαμε τις ίδιες εξομοιώσεις όπως στο ερώτημα 3b απλά αυτήν τη φορά αλλάξαμε,μέσω της γραμμής εντολών την συχνότητα λειτουργίας του επεξεργαστή και την τεχνολογία μνήμης.Παρακάτω παρουσιάζουμε πως αυτές οι αλλαγές που κάναμε επηρεάσανε την εξομοίωση.

Αρχικά,ορίσαμε την συχνότητα λειτουργίας του επεξεργαστή σε MinorCPU μοντέλο,στα 4GHz δίνοντας την εντολή:

    ./build/ARM/gem5.opt configs/example/se.py --cpu-type=MinorCPU --cpu-clock=4GHz --caches -c /home/uglynick/my_gem5/prog_arm

όπως ήταν αναμενόμενο μελετώντας το αρχείο stats.txt της εξομοίωσης βλέπουμε σημαντική βελτίωση στον χρόνο από 0.000039s σε 0.000034s όπως βλέπουμε και παρακάτω:

    final_tick 33544000 # Number of ticks from beginning of simulation (restored from checkpoints and never reset)

    sim_seconds 0.000034 # Number of seconds simulated

    sim_ticks 33544000 # Number of ticks simulated

Αρχικά,ορίσαμε την τεχνολογία μνήμης του επεξεργαστή σε MinorCPU μοντέλο,σε DDR4_2400_16x4 με την εντολή:

    ./build/ARM/gem5.opt configs/example/se.py --cpu-type=MinorCPU --mem-type=DDR4_2400_16x4 --caches -c /home/uglynick/my_gem5/prog_arm

και πάλι βλέπουμε βελτίωση στον χρόνο μικρότερης τάξης από πριν,από 0.000039s σε 0.000038s:

    final_tick 37907000 # Number of ticks from beginning of simulation (restored from checkpoints and never reset)

    sim_seconds 0.000038 # Number of seconds simulated

    sim_ticks 37907000 # Number of ticks simulated

Αντίστοιχα για TimingSimpleCPU μοντέλο ορίσαμε πρώτα την συχνότητα λειτουργίας του επεξεργαστή στα 4GHz με την εντολή:

    ./build/ARM/gem5.opt configs/example/se.py --cpu-type=TimingSimpleCPU --cpu-clock=4GHz --caches -c /home/uglynick/my_gem5/prog_arm

και παρατηρήσαμε βελτίωση στον χρόνο,αντίστοιχη με το MinorCPU μοντέλο και ακόμα καλύτερη,από 0.000049s στα 0.000037s.

    final_tick 37071500 # Number of ticks from beginning of simulation (restored from checkpoints and never reset)

    sim_seconds 0.000037 # Number of seconds simulated

    sim_ticks 37071500 # Number of ticks simulated

Τέλος,ορίσαμε την τεχνολογία μνήμης με την εντολή:

    ./build/ARM/gem5.opt configs/example/se.py --cpu-type=TimingSimpleCPU --mem-type=DDR4_2400_16x4 --caches -c /home/uglynick/my_gem5/prog_arm

και παρατηρήσαμε σαφώς μικρότερη βελτίωση,από 0.000049s στα 0.000048s:

    final_tick 48346000 # Number of ticks from beginning of simulation (restored from checkpoints and never reset)

    sim_seconds 0.000048 # Number of seconds simulated

    sim_ticks 48346000 # Number of ticks simulated

Λίγα λόγια από εμάς

Η συγκεκριμένη εργασία ήταν μία πολύ καλή αφορμή για έμας να μάθουμε και να εξοικειωθούμε με κάποια στοιχεία του gem5 και σαν διαδικασία ήταν απολαυστική.Επίσης,μας έδωσε μία καλύτερη οπτική πάνω στο πως η αρχιτεκτονική κάποιων στοιχείων του hardware επηρεάζει την απόδοση του υπολογιστή μας.Φυσικά,οι απαντήσεις στα παραπάνω ερώτηματα προήλθαν από δικιά μας έρευνα και εξαγωγή συμπερασμάτων και όντας αρχαριοί πιστεύουμε ότι θα υπάρχουν και πολλές αστοχίες τις οποίες θα θέλαμε να μας τις επισημάνεται.Ένα πράγμα που θα ήταν καλό να είχε περιληφθεί στην εκφώνηση της εργασίας θα ήταν να υπήρχε κάποια σύσταση ως προς τους πόσους λογικούς επεξεργαστες(εντολή scons -jN) θα ήταν καλύτερο να επιτρέψουμε στο Vitrual Machine(VM) να χρησιμοποιεί.Μία ασάφεια που εντοπίσαμε στην εκφώνηση της εργασίας ήταν στην δεύτερη σελίδα όπου μας δίνονται οι εντολές για εγκατάσταση του gem5 και συγκεκριμένα στην εντολή:

    $ sudo apt install z1ib1g z1ib1g-dev z1ibc

όπου κανονικά είναι έτσι:

    $ sudo apt install zlib1g zlib1g-dev zlibc

δηλαδή αν κάποιος έγραφε τις εντολές στο terminal μόνος ενώ κοιτούσε και την εκφώνηση δεν θα μπορούσε να ξεχωρίσει τους άσσους(1) από το σύμβολο l. Σε γενικές γραμμές απολαύσαμε την έρευνα και το διάβασμα που κάναμε σχετικά με τον gem5 και συγνώμη για τυχόν εσφαλμένα συμπεράσματα που μπορεί να βγάλαμε μέσω αυτής.
