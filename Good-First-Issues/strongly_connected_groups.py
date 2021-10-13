def add_edge(self, source, target):
        if target >= self.max_n:
            target = target % (self.max_n)

        if target not in self.relationships[source]:
            self.relationships[source].add(target)
            self.relationships[target].add(source)

            self.edges_placed +=1
        return self.relationships


    def create_network(self):
        base_adder = 1
        loop_adder = 0
        n =0

        
        while self.edges_placed < self.max_edges:
            
            while (base_adder + loop_adder)  < self.max_n:
               
                while n < self.max_n:

                    
                    if self.edges_placed == self.max_edges:
                        break
                    else:
                        self.add_edge(n, n+(loop_adder+base_adder))
                        n+=1

               
                loop_adder += 2
                n = 0
           
            base_adder += 1
            loop_adder = 0
