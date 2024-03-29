
<p align="center"><img src="https://arch.cs.ucdavis.edu/assets/images/gem5-logo.png" alt="Gem5-logo" width="250"/></p>

# Εργασία Δεύτερου Εργαστηρίου Αρχιτεκτονικής Υπολογιστών

**Παπακωνσταντίνου Αντώνης, ΑΕΜ 8977**

**Κασιουλής Φίλιππος, ΑΕΜ 8966**

## Ερωτήματα Τρίτου Μέρους
### **Βήμα 1°.** Εξοικειωση με τον εξομειτή Μcpat:

- **Ερώτημα 1.1.**

**Leakage Power**  ή Στατική ισχυς είναι το αποτέλεσμα της ανεπυθυμητης ροης ρεύματος στο  transistor όταν αυτο είναι κλειστό.
Υπάρχου δύο είδη διαρρόης το subtreshold leakage που ωφείλετε στην διαροή ρευματός μεταξύ source και drain οτάν αυτο βρίσκεται κλειστό και το gate leakage οπού ωφείλετε στο ρεύμα που διαρρέι την πύλη.

**Dynamic Power** 
Όπως υποδηλώνει το όνομα, συμβαίνει όταν τα σήματα που περνούν από τα κυκλώματα του τρανζιστορ αλλάζουν τη λογική τους κατάσταση. Εκείνη την στιγμή η ενέργεια  αντλείται από την παροχή ρεύματος για την φορτιστεί η χωρητικότητα του κόμβου εξόδου. 

- **Ερώτημα 1.3.**

Τρέχουμαι το McPAT για τον Xeon (Xeon.xml) και για τον ARM A9 (ARM_A9_2GHz.xml) και παρουσιάζουμε τα αποτελέσματα στο πιο κάτω πίνακα.

|        | **Xeon** |**Arm A9**| 
|---|---|---|
|  Total Leakage |36.8319 W|0.108687 W| 
| RunTime Dynamic|72.9199 W|2.96053  W| 

Ας παρουμέ για παράδειγμα ότι ο Α9 απαιτεί χρόνο 40t sec για ένα πρόγραμμα, τότε ο Xeon θα τρέξει το ίδιο πρόγραμμα σε t sec.
Aρά η ένεργεια που θα καταναλώσει ο Α9 είναι  `40t*(dynamic+leakage)=122.72t Joule` και η αντιστοιχή του Xeon στο ίδιο χρόνο  
`dynamic+leakage)*+39t*leakage=1546t Joule`. Αρά οπως βλέπουμε ο Xeon δεν θα μπορέσει να είναι πιο energy efficient απο το Α9 .


- **Ερώτημα 2.1.**

Η τιμη του **delay**  μπορεί να φανεί απο το  CPI(Cycles Per Instruction)

Η τιμή του **energy** εξάγεται από το χρόνο λειτουργίας του συστήματος απο το αρχείο stats.txt (sim_seconds) του gem5 σε συνδυασμό με το Total Power Consuption(Total Leakage+RunTime Dynamic) απο το McPAT.Αρά η συνολίκη ενέργεια  είναι ` Total_Energy= Total_Power_Consumption * Total_Time`.
