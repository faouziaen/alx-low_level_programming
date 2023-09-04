#include <stdio.h>
#include <stdlib.h>
#include <elf.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

void validateElfFile(unsigned char *identification);
void printElfMagic(unsigned char *identification);
void printElfClass(unsigned char *identification);
void printElfData(unsigned char *identification);
void printElfVersion(unsigned char *identification);
void printElfOsAbi(unsigned char *identification);
void printElfAbiVersion(unsigned char *identification);
void printElfType(unsigned int type, unsigned char *identification);
void printElfEntryPoint(unsigned long int entryPoint, unsigned char *identification);
void closeFile(int fileDescriptor);

/**
 * validateElfFile - Checks if a file is a valid ELF file.
 * @identification: A pointer to an array containing the ELF identification bytes.
 *
 * If the file is not a valid ELF file, it exits with exit code 98.
 */
void validateElfFile(unsigned char *identification)
{
    int index;

    for (index = 0; index < 4; index++)
    {
        if (identification[index] != 127 &&
            identification[index] != 'E' &&
            identification[index] != 'L' &&
            identification[index] != 'F')
        {
            dprintf(STDERR_FILENO, "Error: Not an ELF file\n");
            exit(98);
        }
    }
}

/**
 * printElfMagic - Prints the magic numbers of an ELF header.
 * @identification: A pointer to an array containing the ELF magic numbers.
 *
 * The magic numbers are separated by spaces.
 */
void printElfMagic(unsigned char *identification)
{
    int index;

    printf(" Magic: ");

    for (index = 0; index < EI_NIDENT; index++)
    {
        printf("%02x", identification[index]);

        if (index == EI_NIDENT - 1)
            printf("\n");
        else
            printf(" ");
    }
}

/**
 * printElfClass - Prints the class of an ELF header.
 * @identification: A pointer to an array containing the ELF class.
 */
void printElfClass(unsigned char *identification)
{
    printf(" Class: ");

    switch (identification[EI_CLASS])
    {
    case ELFCLASSNONE:
        printf("none\n");
        break;
    case ELFCLASS32:
        printf("ELF32\n");
        break;
    case ELFCLASS64:
        printf("ELF64\n");
        break;
    default:
        printf("<unknown: %x>\n", identification[EI_CLASS]);
    }
}

/**
 * printElfData - Prints the data encoding of an ELF header.
 * @identification: A pointer to an array containing the ELF data encoding.
 */
void printElfData(unsigned char *identification)
{
    printf(" Data: ");

    switch (identification[EI_DATA])
    {
    case ELFDATANONE:
        printf("none\n");
        break;
    case ELFDATA2LSB:
        printf("2's complement, little endian\n");
        break;
    case ELFDATA2MSB:
        printf("2's complement, big endian\n");
        break;
    default:
        printf("<unknown: %x>\n", identification[EI_CLASS]);
    }
}

/**
 * printElfVersion - Prints the version of an ELF header.
 * @identification: A pointer to an array containing the ELF version.
 */
void printElfVersion(unsigned char *identification)
{
    printf(" Version: %d", identification[EI_VERSION]);

    switch (identification[EI_VERSION])
    {
    case EV_CURRENT:
        printf(" (current)\n");
        break;
    default:
        printf("\n");
        break;
    }
}

/**
 * printElfOsAbi - Prints the OS/ABI of an ELF header.
 * @identification: A pointer to an array containing the ELF OS/ABI.
 */
void printElfOsAbi(unsigned char *identification)
{
    printf(" OS/ABI: ");

    switch (identification[EI_OSABI])
    {
    case ELFOSABI_NONE:
        printf("UNIX - System V\n");
        break;
    case ELFOSABI_HPUX:
        printf("UNIX - HP-UX\n");
        break;
    case ELFOSABI_NETBSD:
        printf("UNIX - NetBSD\n");
        break;
    case ELFOSABI_LINUX:
        printf("UNIX - Linux\n");
        break;
    case ELFOSABI_SOLARIS:
        printf("UNIX - Solaris\n");
        break;
    case ELFOSABI_IRIX:
        printf("UNIX - IRIX\n");
        break;
    case ELFOSABI_FREEBSD:
        printf("UNIX - FreeBSD\n");
        break;
    case ELFOSABI_TRU64:
        printf("UNIX - TRU64\n");
        break;
    case ELFOSABI_ARM:
        printf("ARM\n");
        break;
    case ELFOSABI_STANDALONE:
        printf("Standalone App\n");
        break;
    default:
        printf("<unknown: %x>\n", identification[EI_OSABI]);
    }
}

/**
 * printElfAbiVersion - Prints the ABI version of an ELF header.
 * @identification: A pointer to an array containing the ELF ABI version.
 */
void printElfAbiVersion(unsigned char *identification)
{
    printf(" ABI Version: %d\n", identification[EI_ABIVERSION]);
}

/**
 * printElfType - Prints the type of an ELF header.
 * @type: The ELF type.
 * @identification: A pointer to an array containing the ELF identification bytes.
 */
void printElfType(unsigned int type, unsigned char *identification)
{
    if (identification[EI_DATA] == ELFDATA2MSB)
        type >>= 8;

    printf(" Type: ");

    switch (type)
    {
    case ET_NONE:
        printf("NONE (None)\n");
        break;
    case ET_REL:
        printf("REL (Relocatable file)\n");
        break;
    case ET_EXEC:
        printf("EXEC (Executable file)\n");
        break;
    case ET_DYN:
        printf("DYN (Shared object file)\n");
        break;
    case ET_CORE:
        printf("CORE (Core file)\n");
        break;
    default:
        printf("<unknown: %x>\n", type);
    }
}

/**
 * printElfEntryPoint - Prints the entry point of an ELF header.
 * @entryPoint: The address of the ELF entry point.
 * @identification: A pointer to an array containing the ELF identification bytes.
 */
void printElfEntryPoint(unsigned long int entryPoint, unsigned char *identification)
{
    printf(" Entry point address: ");

    if (identification[EI_DATA] == ELFDATA2MSB)
    {
        entryPoint = ((entryPoint << 8) & 0xFF00FF00) |
                     ((entryPoint >> 8) & 0xFF00FF);
        entryPoint = (entryPoint << 16) | (entryPoint >> 16);
    }

    if (identification[EI_CLASS] == ELFCLASS32)
        printf("%#x\n", (unsigned int)entryPoint);

    else
        printf("%#lx\n", entryPoint);
}

/**
 * closeFile - Closes a file.
 * @fileDescriptor: The file descriptor of the file to close.
 *
 * If the file cannot be closed, it exits with exit code 98.
 */
void closeFile(int fileDescriptor)
{
    if (close(fileDescriptor) == -1)
    {
        dprintf(STDERR_FILENO,
                "Error: Can't close file descriptor %d\n", fileDescriptor);
        exit(98);
    }
}

/**
 * main - Displays the information contained in the ELF header
 * at the start of an ELF file.
 * @argc: The number of arguments supplied to the program.
 * @argv: An array of pointers to the arguments.
 *
 * Return: 0 on success.
 *
 * If the file is not a valid ELF file or the function fails,
 * it exits with exit code 98.
 */
int main(int __attribute__((__unused__)) argc, char *argv[])
{
    Elf64_Ehdr *header;
    int fileDescriptor, bytesRead;

    fileDescriptor = open(argv[1], O_RDONLY);
    if (fileDescriptor == -1)
    {
        dprintf(STDERR_FILENO, "Error: Can't read file %s\n", argv[1]);
        exit(98);
    }
    header = malloc(sizeof(Elf64_Ehdr));
    if (header == NULL)
    {
        closeFile(fileDescriptor);
        dprintf(STDERR_FILENO, "Error: Can't allocate memory\n");
        exit(98);
    }
    bytesRead = read(fileDescriptor, header, sizeof(Elf64_Ehdr));
    if (bytesRead == -1)
    {
        free(header);
        closeFile(fileDescriptor);
        dprintf(STDERR_FILENO, "Error: Can't read file %s\n", argv[1]);
        exit(98);
    }

    validateElfFile(header->e_ident);
    printf("ELF Header:\n");
    printElfMagic(header->e_ident);
    printElfClass(header->e_ident);
    printElfData(header->e_ident);
    printElfVersion(header->e_ident);
    printElfOsAbi(header->e_ident);
    printElfAbiVersion(header->e_ident);
    printElfType(header->e_type, header->e_ident);
    printElfEntryPoint(header->e_entry, header->e_ident);

    free(header);
    closeFile(fileDescriptor);
    return (0);
}
