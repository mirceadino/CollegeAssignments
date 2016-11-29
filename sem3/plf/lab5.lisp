; a)
(defun do_merge (L R)
  (cond
    ((null L) R)
    ((null R) L)
    ((<= (car L) (car R)) (append (list (car L)) (do_merge (cdr L) R)))
    (T (append (list (car R)) (do_merge L (cdr R))))
    )
  )

; b)
(defun repl (L R E)
  (cond
    ((null L) NIL)
    ((listp (car L))
     (append (list (repl (car L) R E)) (repl (cdr L) R E)))
    ((not (equal (car L) E))
     (append (list (car L)) (repl (cdr L) R E)))
    ((equal (car L) E)
     (append R (repl (cdr L) R E)))
    )
  )

; c)
(defun do_reverse (L)
  (cond
    ((null L) L)
    (T (append (do_reverse (cdr L)) (list (car L))))
    )
  )

(defun div (A B)
  (/ (- A (mod A B)) B))

(defun sum_r (L R TR)
  (cond
    (
     (and (and (null L) (null R)) (= TR 0))
     NIL)
    (
     (and (null L) (null R))
     (list TR))
    (
     (and (not (null L)) (null R))
     (append
       (list (mod (+ (car L) TR) 10))
       (sum_r (cdr L) NIL (div (+ (car L) TR) 10))
       ))
    (
     (and (null L) (not (null R)))
     (append
       (list (mod (+ (car R) TR) 10))
       (sum_r NIL (cdr R) (div (+ (car R) TR) 10))
       ))
    (T
      (append
        (list (mod (+ (+ (car L) (car R)) TR) 10))
        (sum_r (cdr L) (cdr R) (div (+ (+ (car L) (car R)) TR) 10))
        ))
    )
  )

(defun sum (L R)
  (do_reverse (sum_r (do_reverse L) (do_reverse R) 0))
  )

; d)
(defun cmmdc (A B)
  (cond
    ((< A B) (cmmdc B A))
    ((= B 0) A)
    (T (cmmdc B (mod A B)))
    )
  )

(defun gcd_l (L)
  (cond
    ((null L) 0)
    ((numberp (car L)) (cmmdc (car L) (gcd_l (cdr L))))
    (T (gcd_l (cdr L)))
    )
  )
