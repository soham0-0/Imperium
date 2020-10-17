#ifndef IMPERIUM_H
#define IMPERIUM_H
#include <string>

class imperium {
    std::string root;
    std::string doesExist(std::string) const;
    void isRepo() const;
    std::string getTime() const;
    std::string relativePath(std::string) const;
    bool isIgnored(std::string) const;
    void addToLog(std::string) const;
    void addToCache(std::string) const;
    std::string getHash(std::string) const;
    void purgeAdd() const;
    void updateCommitLog(std::string, std::string) const;
    bool isSame(std::string, std::string) const;
    public:
    /*
        Constructor
        Sets root to present working directory.
        Decrypts the imperium folder.
    */
    imperium();

    /*
        Prints help for the required section, if none specified, prints all help.
        @param helpQuery: Required help section name
    */
    void getHelp(std::string) const;

    /*
        Sets the root for repo directory if provided.
        @param path: path of the repo directory relative to present working directory.
    */
    void setRoot(std::string);

    //  Initializes empty repository at root directory
    void init() const;

    /*  
        Adds current state to the staging area.
        @param path: path of file to be added
    */
    void add(std::string) const;

    /*
        Commits the tracked changes
        @param message: Entered commit messagee
    */
    void commit(std::string) const;

    /*
        Get Log of all commits
        @param flag: optional flag (--oneline), if passed, shortens the output.
    */
    void getCommitLog(std::string) const;

    /*  
        Changes the current contents of the repo to that of a previous commit
        @param hash: commit hash of the desired commit 
    */
    void checkout(std::string) const;

    /*
        Reverts the changes made in the specified commit
        @param hash: commit hash of the desired commit
    */
    void revert(std::string) const;

    //  Shows status of files in the repository
    void getStatus() const;

    //  Unfreezes the commands
    void resolve() const;

    /*
        Finds the appropriate hash using the passed argument
        @param hashQuery: argument entered
    */
    std::string headHunter(std::string) const;

    //  checks if the repository is frozen due to conflict
    bool frozen() const;

    /*
        Destructor
        Encrypts the imperium folder.
    */
    ~imperium();
};

#endif