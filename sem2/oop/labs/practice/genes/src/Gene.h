#ifndef GENE_H_
#define GENE_H_

#include <string>
#include <fstream>

class Gene {
  public:
    Gene(const std::string& organism = "", const std::string& name = "", const std::string& sequence = "");

    std::string getName() const;
    void setName(const std::string& name);
    std::string getOrganism() const;
    void setOrganism(const std::string& organism);
    std::string getSequence() const;
    void setSequence(const std::string& sequence);

    bool operator<(const Gene& that) const;

  private:
    std::string organism_;
    std::string name_;
    std::string sequence_;
};

std::istream& operator>>(std::istream& in, Gene& G);
std::ostream& operator<<(std::ostream& out, Gene& G);

#endif /* GENE_H_ */
