class Player:
    MAX_LEVEL = 40
    def __init__(self, x, y):
        self.name = x
        self.health = y
        self.level = 1
    def __str__(self):
        return "<{}:{}, {} HP>".format(self.name, self.level, self.health)
    def __repr__(self):
        return "<{}:{}, {} HP>".format(self.name, self.level, self.health)
    def __lt__(self, other):
        if self.level!=other.level:
            return self.level<other.level
        return self.health<other.health
    def find_strongest(l):
        strongest = l[0]
        for p in l:
            if p.level>strongest.level:
                strongest=p
        return p
    def compare(p1, p2):
        if p1.level > p2.level:
            return 1
        if p1.level < p2.level:
            return -1
        return 0
    def take_hit(self, damage):
        self.health-=damage
    def heal(self, amount):
        self.health+=amount
    def level_up(self):
        self.level+=1
        self.health = 100
    def describe(self):
        print("<{}, {} HP>".format(self.name, self.health))
