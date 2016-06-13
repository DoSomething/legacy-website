## Retrieve all terms

Currently only returns Cause terms. Available to public, but users with relevant access will see a Inbox Count.

```
GET https://www.dosomething.org/api/v1/terms
```

## Retrieve a term

```
GET https://www.dosomething.org/api/v1/taxonomy_term/[term_id]
```

#### Example

**Request:**

https://www.dosomething.org/api/v1/taxonomy_term/123

**Response:**

```
{
  tid: "123",
  vid: "5",
  name: "Sports",
  description: "",
  format: "markdown",
  weight: "0",
  uuid: "9fb331e7-e09e-4a98-8cae-0234e3855305",
  vocabulary_machine_name: "tags",
  metatags: [ ]
}
```

## Get Term pending Reportback Files

Must have access to review reportbacks.

**GET** `https://www.dosomething.org/api/v1/terms/:tid/inbox?count=1`
