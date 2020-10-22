(defn factorial [n]
  (reduce * (range 1 (inc n))))

(factorial 5)  
